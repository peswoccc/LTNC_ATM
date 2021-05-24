bool check_pass(tai_khoan &tk, int fail, vector <tai_khoan> &v, string &pass)
{
    if (fail == 5)
        return 0;
    cin >> pass;
    while(pass != tk.pass)
    {
        if (fail != 4) cout << text[55][language];
        return check_pass(tk, fail+1, v, pass);
    }
    return 1;
}

void thong_bao_tk_bi_khoa()
{
    cout << text[56][language];
    getch();
    thanks();
}

void check_id_admin(tai_khoan &tk, vector<tai_khoan> &v)
{
    cout << text[57][language];
    cin >> tk.pass;
    while (tk.pass != "14102002")
    {
        system("cls");
        cout << text[58][language];
        cin >> tk.pass;
    }
    system("cls");
    ad_min(tk, v);
}

void check_id(tai_khoan &tk, vector <tai_khoan> &v)
{
    cout << text[59][language];
    cin >> tk.id;
    if (tk.id == "admin")
    {
        check_id_admin(tk,v);
        system("cls");
        cout << text[60][language] << text[61][language];
        int dangxuat;
        cin >> dangxuat;
        if(dangxuat == 1)
        {
            system("cls");
            check_id(tk, v);
        }
        else thanks();
    }
    else
    {
        while (tk.id != "admin" && !id_exist(tk.id, v))
        {
            system("cls");
            cout << text[44][language];
            cin >> tk.id;
        }
        if (tk.id == "admin")
        {
            check_id_admin(tk, v);
        }
        else
        {
            for (int i = 0; i < v.size(); i++)
                if (tk.id == v[i].id)
                    tk = v[i];
            if (tk.locked)
                thong_bao_tk_bi_khoa();
            else
            {
                string pass;
                cout << text[57][language];
                if (check_pass(tk, 0, v, pass))
                    main_pro(tk, v);
                else
                {
                    tk.locked = 1;
                    save_tk(tk);
                    v = file_to_tk();
                    thong_bao_tk_bi_khoa();
                }
            }
        }
        system("cls");
        cout << text[60][language] << text[61][language];
        int dangxuat;
        cin >> dangxuat;
        if(dangxuat == 1)
        {
            system("cls");
            check_id(tk, v);
        }
        else thanks();
    }
}
