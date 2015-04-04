//AC Em 04/04/2013
//RunTime 0.404
//Anderson Zudio, Pedro FZS

#include <list>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    list<char> l;
    list<char>::iterator it;
    while(cin >> s)
    {
        it = l.begin();
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '[') it = l.begin();
        else if(s[i] == ']') it = l.end();
        else l.insert(it,s[i]);
    }

    for(it = l.begin();it != l.end(); it++) cout << *it;
    cout << endl; l.clear();
    }
    return 0;
}
