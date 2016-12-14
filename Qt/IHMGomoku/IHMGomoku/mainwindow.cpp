#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow), canvas(FIELDS_WIDTH * FIELD_XY - 1, FIELDS_HEIGHT * FIELD_XY - 1),
  _Running(false)
{
	ui->setupUi(this);
    this->setWindowTitle("Gomoku");
    this->setFixedSize(500, 560);
    this->resize(500, 560);

    ui->menuFile->setTitle("Game");
    delete ui->action_About;
    delete ui->action_Screenshot;
    ui->statusLabel->setGeometry(QRect(0, 0, 500, 40));

	this->setWindowIcon(QIcon(IMAGE_ICON));
    ui->fieldLabel->installEventFilter(this);
    initialize();
}

void MainWindow::initialize()
{
	for(int x=0; x < FIELDS_WIDTH; x++)
    {
		for(int y=0; y < FIELDS_HEIGHT; y++)
        {
			this->fields[x][y] = NO_PLAYER;
        }
    }
    turn = CIRCLE;
    nombreCase = FIELDS_WIDTH * FIELDS_HEIGHT;
    qDebug() << "nombreCase :" << FIELDS_WIDTH * FIELDS_HEIGHT;
    qDebug() << "fieldLabel setFixedSize :" << FIELDS_WIDTH * FIELD_XY << "," << FIELDS_HEIGHT * FIELD_XY;
	ui->fieldLabel->setFixedSize(FIELDS_WIDTH * FIELD_XY, FIELDS_HEIGHT * FIELD_XY);
    draw();
}

void MainWindow::draw(std::map<int,char> _board)
{
    if (_Running == true)
    {
        int x = -1, y;
        for (int i = 0; i < nombreCase; i++)
        {
             if (i % 19 == 0)
            {
                x++;
                 y = -1;
            }
            if (_board[i] == 'x')
                fields[x][++y] = CROSS;
            else if (_board[i] == 'o')
                 fields[x][++y] = CIRCLE;
            else
                 fields[x][++y] = NO_PLAYER;
        }
    draw();
    }
}

void MainWindow::draw() /* Dessin le tableau*/
{
    QPainter painter(&canvas);
    painter.setBrush(Qt::NoBrush);
    painter.setPen(Qt::NoPen);

    // background
    painter.fillRect(0, 0, canvas.width(), canvas.height(), Qt::white);

    // fields
    painter.setPen(Qt::black);
    for(int x = 0; x < FIELDS_WIDTH; x++)
    {
        for(int y = 0; y < FIELDS_HEIGHT; y++)
        {
            painter.drawRect(x * FIELD_XY - 1, y * FIELD_XY - 1, FIELD_XY, FIELD_XY);
            if(fields[x][y] == CIRCLE)
            {
                painter.fillRect(x * FIELD_XY, y * FIELD_XY, FIELD_XY - 1, FIELD_XY - 1, Qt::white);
                QColor black("#000000");
                Qt::BrushStyle bstyle = Qt::SolidPattern;
                QBrush bbrush(black, bstyle);
                painter.setBrush(bbrush);
                painter.drawEllipse(QPoint(x * FIELD_XY, y * FIELD_XY), 10, 10);
            }
            else if(fields[x][y] == CROSS)
            {
                painter.fillRect(x * FIELD_XY, y * FIELD_XY, FIELD_XY - 1, FIELD_XY - 1, Qt::white);
                QColor red("#FF0000");
                Qt::BrushStyle rstyle = Qt::SolidPattern;
                QBrush rbrush(red, rstyle);
                painter.setBrush(rbrush);
                painter.drawEllipse(QPoint(x * FIELD_XY, y * FIELD_XY), 10, 10);
            }
            else
            {
                painter.fillRect(x * FIELD_XY, y * FIELD_XY, FIELD_XY - 1, FIELD_XY - 1, Qt::white);
            }

        }
    }
    ui->fieldLabel->setPixmap(canvas);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::newGame()
{
   ui->statusLabel->setText("JOUEUR ");
   _IA = false;
   _regleCinqCassable = false;
   _regleDoubleTrois = false;
   _ta = 1;
   questionIA();
   questionOrbreAI();
   questionDoubleTrois();
   questionCinqCassable();
   _Running = true;
   initialize();
}

void    MainWindow::questionIA()
{
    if (QMessageBox::Yes == QMessageBox(QMessageBox::Information, "IA", "Voulez-vous l'IA ?", QMessageBox::Yes|QMessageBox::No).exec())
       _IA = true;
    else
    {
        _IA = false;
        _j1 = "JOUEUR 1";
        _j2 = "JOUEUR 2";
    }
}

void    MainWindow::questionOrbreAI()
{
    if (_IA == true)
    {
        if (QMessageBox::Yes == QMessageBox(QMessageBox::Information, "IA", "Voulez-vous que l'IA joue en premier ?", QMessageBox::Yes|QMessageBox::No).exec())
        {
            _ta = 0;
            _j1 = "AI";
            _j2 = "VOUS";
        }
        else
        {
            _ta = 1;
            _j1 = "VOUS";
            _j2 = "AI";
        }
     }
    ui->statusLabel->setText(_j1);
}

void    MainWindow::questionDoubleTrois()
{
    if (QMessageBox::Yes == QMessageBox(QMessageBox::Information, "Double Trois", "Voulez-vous la régle du Double Trois", QMessageBox::Yes|QMessageBox::No).exec())
        _regleDoubleTrois = true;
    else
        _regleDoubleTrois = false;
}

void   MainWindow::questionCinqCassable()
{
    if (QMessageBox::Yes == QMessageBox(QMessageBox::Information, "Cinq Cassable", "Voulez-vous la régle du Cinq Cassable", QMessageBox::Yes|QMessageBox::No).exec())
        _regleCinqCassable = true;
    else
        _regleCinqCassable = false;
}

bool MainWindow::eventFilter(QObject* object, QEvent* e)
{
    if (_Running == true)
       {
        if(object != ui->fieldLabel || e->type() != QEvent::MouseButtonPress)
        {
            return false;
        }
        const QMouseEvent* event = static_cast<const QMouseEvent*>(e);

        int x = event->x() / FIELD_XY;
        int y = event->y() / FIELD_XY;

        qDebug() << "Click ici x:" << x << "|y:" << y << "Case : ";
        if (fields[x][y] == 1)
            qDebug() << "O";
        else if (fields[x][y] == 2)
            qDebug() << "X";
        else
            qDebug() << "NULL";

        this->fieldClicked(x, y);
       }
	return false;
}

void MainWindow::fieldClicked(int x, int y)
{
	if(fields[x][y] > NO_PLAYER) // cannot reclaim claimed field
    {
        qDebug() << "fields[x][y]";
        if (fields[x][y] == 1)
            qDebug() << "O";
        else if (fields[x][y] == 2)
            qDebug() << "X";
        else
            qDebug() << "NULL";

		return;
    }

	if(turn == NO_PLAYER)
    {
        qDebug() << "No_player";
		return;
    }

    if (fields[x][y] == NO_PLAYER)
    {
        fields[x][y] = turn;
        draw();
    }

	// if all the fields are full, it's a tie
    nombreCase--;
    if(nombreCase <= 0)
	{
		turn = NO_PLAYER;
		winner = 0;
        showWinner(winner);
		return;
	}

	// swap turn
	if(turn == CIRCLE)
	{
        ui->statusLabel->setText(_j2);
		turn = CROSS;
	}
	else
	{
        ui->statusLabel->setText(_j1);
		turn = CIRCLE;
	}
}

void MainWindow::showWinner(char winner)
{
    if (_Running == true)
    {
        QMessageBox msgbox;
        QString text;
        if(winner == 0)
            text = "It's a tie!";
        else if(winner == 'o')
            text = "Circle wins!";
        else if(winner == 'x')
            text = "Cross wins!";
        else
            text = "Unknown error. Could not determine winner";

        ui->statusLabel->setText(text);
        msgbox.setWindowTitle("Game Over");
        msgbox.setText(text);
        msgbox.exec();
        this->initialize();
        _Running = false;
    }
}
