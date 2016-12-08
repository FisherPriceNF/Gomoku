using UnityEngine;
using System.Collections;
using System.Collections.Generic;
using System;

public class MenuMain : MonoBehaviour {

    private bool _isFirstMenu = true;
    private bool _isOptionMenu = false;
    private bool _isChoixGame = false;
    private bool _isRegleDoubleTrois = false;
    private bool _isRegleCinqCasse = false;

    // Use this for initialisation
    void     Start()
    {

    }

    // Update is called once per farme.
    void     Update()
    {
    }

    void     OnGUI()
    {
        FirstMenu();
        OptionsMenu();
        ChoixGame();
        ChoixGame();
    }

    void    FirstMenu()
    {
        if (this._isFirstMenu)
        {
            if (GUI.Button(new Rect(Screen.width / 2 - 150, Screen.height / 2 + 23, 271, 36),"New Game"))
            {
                _isFirstMenu = false;
                _isChoixGame = true;
                _isOptionMenu = false;
                this.ChoixGame();
            }
            if (GUI.Button(new Rect(Screen.width / 2 - 150, Screen.height / 2 + 73, 271, 36), "Options"))
            {
                _isFirstMenu = false;
                _isChoixGame = false;
                _isOptionMenu = true;
                this.OptionsMenu();
            }
            if (GUI.Button(new Rect(Screen.width / 2 - 150, Screen.height / 2 + 123, 271, 36), "Quit Game"))
            {
                Application.Quit();
            }
        }
    }

    void    OptionsMenu()
    {
        if (this._isOptionMenu)
        {
            // --- Option Double Trois.
            GUI.TextField(new Rect(Screen.width / 2 - 150, Screen.height / 2 + 20, 271, 36), "Activer la régle du double Trois ?");
            if (GUI.Button(new Rect(Screen.width / 2 + 73, Screen.height / 2 + 60, 50, 36), "Oui"))
            {
                _isRegleDoubleTrois = true;
            }       
            if (GUI.Button(new Rect(Screen.width / 2 - 150, Screen.height / 2 + 60, 50, 36), "Non"))
            {
                _isRegleDoubleTrois = false;
            }

            String RegleDoubleTrois = "";
            if (this._isRegleDoubleTrois == true)
                RegleDoubleTrois = "Double Trois : Activé.";
            else
                RegleDoubleTrois = "Double Trois : Déactivé.";
            GUI.TextArea(new Rect(Screen.width / 2 - 90, Screen.height / 2 + 60, 150, 36), RegleDoubleTrois);
            // --- Option Cinq Cassable.
            GUI.TextField(new Rect(Screen.width / 2 - 150, Screen.height / 2 + 110, 271, 36), "Activer la régle du cinq cassable ?");
            if (GUI.Button(new Rect(Screen.width / 2 + 73, Screen.height / 2 + 151, 50, 36), "Oui"))
            {
                _isRegleCinqCasse = true;
            }
            if (GUI.Button(new Rect(Screen.width / 2 - 150, Screen.height / 2 + 151, 50, 36), "Non"))
            {
                _isRegleCinqCasse = false;
            }

            String RegleCinqCassable = "";
            if (this._isRegleCinqCasse == true)
                RegleCinqCassable = "Cinq Cassable : Activé.";
            else
                RegleCinqCassable = "Cinq Cassable : Déactivé.";
            GUI.TextArea(new Rect(Screen.width / 2 - 93, Screen.height / 2 + 151, 160, 36), RegleCinqCassable);
            if (GUI.Button(new Rect(Screen.width / 2 - 150, Screen.height / 2 + 200, 271, 36), "Return Game"))
            {
                _isFirstMenu = true;
                _isOptionMenu = false;
                _isChoixGame = false;
            }
        }
    }

    void ChoixGame()
    {
        if (this._isChoixGame)
        {
            if (GUI.Button(new Rect(Screen.width / 2 - 150, Screen.height / 2 + 23, 271, 36), "Player 1"))
            {
            #pragma warning disable CS0618 // Le type ou le membre est obsolète
                Application.LoadLevel("Level01"); // Avec Joueur.
            #pragma warning restore CS0618 // Le type ou le membre est obsolète
            }
            if (GUI.Button(new Rect(Screen.width / 2 - 150, Screen.height / 2 + 73, 271, 36), "Player 2"))
            {
            #pragma warning disable CS0618 // Le type ou le membre est obsolète
                Application.LoadLevel("Level01"); // Avec AI.
            #pragma warning restore CS0618 // Le type ou le membre est obsolète
            }
            if (GUI.Button(new Rect(Screen.width / 2 - 150, Screen.height / 2 + 123, 271, 36), "Return Game"))
            {
                _isFirstMenu = true;
                _isOptionMenu = false;
                _isChoixGame = false;
            }
        }
    }
}
