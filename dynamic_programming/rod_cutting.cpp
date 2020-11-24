#include <iostream>

using namespace std;

int maximizeTheCuts(int n, int x, int y, int z)
{
    int t[n+1][3+1];
    int lens[] = {x, y, z};

    for(int i = 0; i < 4; i++){
        for (int j = 0; j <= n; j++){
            t[i][j] = 0;
        }
    }
    for(int i = 1; i < 4; i++){
        for (int j = 0; j <= n; j++){

            if ( lens[i-1] <= j){
                t[i][j] = max(t[i-1][j] , lens[i-1]+ t[i][j - lens[i - 1]]);
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    for(int i = 0; i < 4; i++){
        for (int j = 0; j <= n; j++){
            cout << t[i][j] << " ";
        }
        cout << endl;
    }

    return t[3][n];
}

int maximizeTheCutsRec(int n, int lens[]){




}

int main(){
    int n, x, y, z;

    cin >> n >> x >> y >> z;
    int lens[] = {x, y, z};

    cout << maximizeTheCuts(n, lens) ;

}
