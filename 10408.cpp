//AC em 16/01/2012
//Anderson Zudio

/*#include <iostream>
#include <algorithm>

using namespace std;

void farey(int n) {
  int h = 0, k = 1, x = 1, y = 0;

  do {
    cout << h << '/' << k << endl;

    int r = (n-y)/k;
    y += r*k;
    x += r*h;

    swap(x,h);
    swap(y,k);
    x = -x;
    y = -y;
  } while (k > 1);
  cout << "1/1" << endl;
}

int main() {
  int n;
  while (cin >> n)
    farey(n);
}*/

#include <iostream>

using namespace std;

long long int n, m;

int gerafarey(int n)
{
  long long int h = 0, k = 1, x = 1, y = 0, aux, aux2;

  for(int i=1;i <= m;i++)
  {
     aux = (n-y)/k;
     y += aux * k;
     x += aux * h;
     aux2 = x; x = h; h = aux2;
     aux2 = y; y = k; k = aux2;
     x = -x; y = -y;
  }
  cout << h << '/' << k << endl;
}

int main() {

  while (cin >> n, cin >> m)
    gerafarey(n);

}
