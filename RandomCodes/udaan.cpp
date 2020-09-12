#include <bits/stdc++.h>
using namespace std;

class Screen
{
private:
    string screen_name;
    int row;
    int seats_per_row;
    set<int> aisle_seat_list;
    set<pair<int, int>> reserved_seats_list;
    set<pair<int, int>> unreserved_seats_list;

public:
    Screen(string screen_name, int row, int seats_per_row, set<int> aisle_seat_list, set<pair<int, int>> unreserved_seats_list)
    {
        this->screen_name = screen_name;
        this->row = row;
        this->seats_per_row = seats_per_row;
        this->aisle_seat_list = aisle_seat_list;
        this->unreserved_seats_list = unreserved_seats_list;
    }

    void reserveseat(string screenname, int rownum, vector<int> seatnums)
    {
        set<pair<int, int>> s;
        set<pair<int, int>> us; // for unreserved seat list
        us = this->unreserved_seats_list;

        for (int i = 0; i < seatnums.size(); i++)
        {
            pair<int, int> p;
            p.first = rownum;
            p.second = seatnums[i];

            if (s.find(p) == s.end()) // if not reserved
            {
                s.insert(p);
                us.erase(p);
            }
            else // if reserved
            {
                cout << "failure" << endl;
                return;
            }
        }

        this->unreserved_seats_list = us;
        this->reserved_seats_list = s;
        return;
    }

    void getUnreserveSeats(string screename, int rownum)
    {
        set<pair<int, int>> us;
        us = this->unreserved_seats_list;

        for (auto itr = us.begin(); itr != us.end(); itr++)
        {
            pair<int, int> p;
            p = *itr;
            if (p.first == rownum)
                cout << p.second << " ";
        }
        cout << endl;
        return;
    }

    void suggestSeats(string screenname, int numofseat, int rownum, int choice)
    {
        bool possible_further = true;
        set<pair<int, int>> s;
        s = this->reserved_seats_list;

        vector<int> suggest;

        pair<int, int> p;
        p.first = rownum;
        p.second = choice;

        if (s.find(p) != s.end()) // if seat is already booked
        {
            cout << "none" << endl;
            return;
        }
        else // if the seat is not booked
        {
            int choicenum = choice; // so as to not destroy the original choice value
            suggest.push_back(choicenum);
            while (possible_further) // first decreasing choice
            {
                choicenum--;
                pair<int, int> p;
                p.first = rownum;
                p.second = choicenum;
                if (s.find(p) != s.end()) // if this seat is already booked
                {
                    possible_further = false;
                    break;
                }
                else // if not booked
                {
                    suggest.push_back(choicenum);
                }
            }

            choicenum = choice;
            suggest.push_back(choice);
            while (possible_further) // first decreasing choice
            {
                choice++;
                pair<int, int> p;
                p.first = rownum;
                p.second = choice;
                if (s.find(p) != s.end()) // if this seat is already booked
                {
                    possible_further = false;
                    break;
                }
                else // if not booked
                {
                    suggest.push_back(choice);
                }
            }
        }

        sort(suggest.begin(), suggest.end());
        for (int i = 0; i < suggest.size(); i++)
            cout << suggest[i] << " ";

        return;
    }
};

map<string, Screen *> screen_set;

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    while (n--)
    {
        string type;
        cin >> type;

        if (type == "add-screen")
        {

            string screenname;
            cin >> screenname;
            int rownum;
            int total_seats_per_row;
            set<int> aisle_seat_list;
            cin >> rownum >> total_seats_per_row;

            string buffer;
            int data;
            getline(cin, buffer);
            istringstream iss(buffer);
            while (iss >> data)
                aisle_seat_list.insert(data);

            set<pair<int, int>> unreserved_list;

            for (int i = 1; i < rownum; i++)
            {
                for (int j = 1; j < total_seats_per_row; j++)
                {
                    pair<int, int> p;
                    p.first = i;
                    p.second = j;
                    unreserved_list.insert(p);
                }
            }

            if (screen_set.find(screenname) != screen_set.end())
            {
                cout << "failure" << endl;
                return;
            }

            Screen obj(screenname, rownum, total_seats_per_row, aisle_seat_list, unreserved_list);
            screen_set.insert(pair<string, Screen>(screenname, obj));
            cout << "success" << endl;
        }
        else if (type == "reserve-seat")
        {
            string screenname;
            int rownum;
            set<int> reserve;

            cin >> screenname;
            cin >> rownum;

            string buffer;
            int data;
            getline(cin, buffer);
            istringstream iss(buffer);
            while (iss >> data)
                reserve.insert(data);

            if (screen_set.find(screenname) != screen_set.end())
            {
                screenname.reserveseat(screenname, rownum, reserve);
            }
            else
            {
                cout << "failure" << endl;
                return;
            }
        }
        else if (type == "get-unreserved-seats")
        {
            string screenname;
            int rownum;

            cin >> screenname;
            cin >> rownum;

            if (screen_set.find(screenname) != screen_set.end())
            {
                screenname.getUnreserveSeats(screenname, rownum);
            }
            else
            {
                cout << "failure" << endl;
                return;
            }
        }
        else
        {
            string screenname;
            int seatnum;
            int rownum;
            int choice;
            cin >> screenname >> seatnum >> rownum >> choice;

            if (screen_set.find(screenname) != screen_set.end())
            {
                screenname.suggestSeats(screenname, seatnum, rownum, choice);
            }
            else
            {
                cout << "failure" << endl;
                return;
            }
        }
    }
}