using UnityEngine;
using System.Collections;
using System.Collections.Generic;
using System;

public class MenuMain : MonoBehaviour {
    
     private bool _isFirstMenu = false;
     private bool _isOptionMenu = true;
     private bool _isRegleTrois = false;

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
        LoadGameMenu();
        OptionsMenu();
    }

    void    FirstMenu()
    {
        if (this._isFirstMenu)
        {
            if (GUI.Button(new Rect(Screen.width / 2 - 150, Screen.height / 2 + 23, 271, 36),"New Game"))
            {
                #pragma warning disable CS0618 // Le type ou le membre est obsolète
                Application.LoadLevel("Level01");
                #pragma warning restore CS0618 // Le type ou le membre est obsolète
            }
            if (GUI.Button(new Rect(Screen.width / 2 - 150, Screen.height / 2 + 73, 271, 36), "Options"))
            {
                _isFirstMenu = false;
                _isOptionMenu = true;
                this.OptionsMenu();
            }
            if (GUI.Button(new Rect(Screen.width / 2 - 150, Screen.height / 2 + 123, 271, 36), "Quit Game"))
            {
                Application.Quit();
            }
        }
    }

    void    LoadGameMenu()
    {

    }

    void    OptionsMenu()
    {
        if (this._isOptionMenu)
        {
            GUI.TextField(new Rect(Screen.width / 2 - 150, Screen.height / 2 + 20, 271, 36), "Activer la régle de trois ?");
            if (GUI.Button(new Rect(Screen.width / 2 + 73, Screen.height / 2 + 63, 50, 36), "Oui"))
            {
                _isRegleTrois = true;
            }
            if (GUI.Button(new Rect(Screen.width / 2 - 150, Screen.height / 2 + 63, 50, 36), "Non"))
            {
                _isRegleTrois = false;
            }
            if (GUI.Button(new Rect(Screen.width / 2 - 150, Screen.height / 2 + 123, 271, 36), "Return Game"))
            {
                _isFirstMenu = true;
                _isOptionMenu = false;
            }
        }
    }
}
