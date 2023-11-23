#include <iostream>
using namespace std;

#define N 3

class tictactoe {
    public:
        tictactoe();
        bool play(int x, int y);
        char chek_whinner();
        void print();
        void next_player();
        char get_player() const;
    private:
        char array[N][N];
        char player;
};

int main() {

    tictactoe t;
    int x,y, step = 0;

    while(true) {

        cout<<endl<<"Grid:"<<endl;
        t.print();
        cout<<"The player of this turn is: "<<t.get_player()<<endl;

        cout<<"Give x position: "<<endl;
        cin>>x;
        cout<<"Give y position: "<<endl;
        cin>>y;

        //If something gose wrong start drom the begin
        if (!t.play(x,y)) {
            cout<<"Wrong mouve";
            continue;
        } else  
            step++;

        //Check winner and exit
        if (t.chek_whinner() != '-')
        {
            cout<<endl<<"Winner is "<<t.chek_whinner()<<endl;
            t.print();
            break;
        } else if(step == 9) {  //if the is no winner
            cout<<endl<<"Its a Draw!"<<endl;
            t.print();
            break;
        } else  
            t.next_player();    //Change players

    }

    return 0;
}

//Constuctor
tictactoe::tictactoe() {
    int i,j;

    for(i=0; i<N; i++)
        for(j=0; j<N; j++) 
            array[i][j] = '-';
    
    player = 'X';
}

bool tictactoe::play(int x, int y)
{
    if (array[x][y] == '-') {
        array[x][y] = player;
        return true;
    } else 
        return false;
}

char tictactoe::chek_whinner() {

    int i, j;

    //cheking lines
    for (i=0; i<N; i++) {
        if (array[i][0]==array[i][1] && array[i][1] == array[i][2])
            return array[i][0];
    }

    //colums
    for (j=0; j<N; j++) {
        if (array[0][j]==array[1][j] && array[1][j] == array[2][j])
            return array[0][j];
    }

    //diagnoal
    if (array[0][0] == array[1][1] && array[1][1] == array[2][2])
        return array[0][0];

    if (array[0][2] == array[1][1] && array[1][1] == array[2][0])
        return array[1][1];

    //default
    return '-';
}

void tictactoe::print() {

    int i, j;

    cout<<"#############"<<endl;
    for(i=0; i<N; i++) {
        cout<<"# ";
        for(j=0; j<N; j++) {
            cout<<array[i][j]<<" # ";
        }
        cout<<endl;
        cout<<"#############"<<endl;
    }
}

void tictactoe::next_player() {
    if (player == 'X') 
        player = 'O';
    else
        player = 'X';
}

char tictactoe::get_player() const{
    return player;
}