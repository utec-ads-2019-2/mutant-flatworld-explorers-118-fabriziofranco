#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Robot{

    private:
        int pos_x;
        int pos_y;
        int Xmax;
        int Ymax;
        char orientation;
        bool is_lost;
    public:
        Robot(int xx,int yy, int x,int y,char orientation1){
            Xmax=xx; Ymax=yy;
            pos_x=x; pos_y=y; is_lost= false;
            orientation=orientation1;
        }

        void validar_lost(vector<vector<bool>>&map_of_lost){
            if (pos_x >Xmax || pos_y > Ymax || pos_x < 0 || pos_y < 0) {
                switch (orientation) {
                    case 'N':
                        pos_y--;
                        break;
                    case 'E':
                        pos_x--;
                        break;
                    case 'S':
                        pos_y++;
                        break;
                    case 'W':
                        pos_x++;
                        break;
                }
                if (map_of_lost[pos_x][pos_y])
                    return;
                is_lost = true;
                map_of_lost[pos_x][pos_y] = true;
            }
        }

        void avanzar(){
                switch(orientation){
                    case 'N':
                        pos_y++;
                        break;
                    case 'E':
                        pos_x++;
                        break;
                    case 'W':
                        pos_x--;
                        break;
                    case 'S':
                        pos_y--;
                        break;
            }
        }
        
        void rotar_derecha(){
                switch(orientation){
                    case 'N':{
                        orientation='E';
                        break;}
                    case 'E':{
                        orientation='S';
                        break;}
                    case 'S':{
                        orientation='W';
                        break;}
                    case 'W':{
                        orientation='N';
                        break;}
                }
        }

        void rotar_izquierda(){
                switch(orientation){
                    case 'N':{
                        orientation='W';
                        break;}
                    case 'W':{
                        orientation='S';
                        break;}
                    case 'S':{
                        orientation='E';
                        break;}
                    case 'E':{
                        orientation='N';
                        break;}
            }
        }

        void move(char movimiento,vector<vector<bool>>&map_of_lost){
            switch(movimiento){
                case 'F':{
                    avanzar();
                    break;}
                case 'R':{
                    rotar_derecha();
                    break;}

                case 'L':{
                    rotar_izquierda();
                    break;}
            }
            validar_lost(map_of_lost);
        }
        
        void Recorrer(const string& movimientos,vector<vector<bool>>&map_of_lost){
            for(auto movimiento:movimientos){
                move(movimiento,map_of_lost);
                if(is_lost)
                    return;}
        }


        void Imprimir_robot(){
            cout<<pos_x<<" "<<pos_y<<" "<<orientation;
            if(is_lost)
                cout<<" LOST";
            cout<<endl;
        }


        ~Robot()= default;

};

int main(){
    int dimension_x,dimension_y,pos_x,pos_y;
    char orientation;
    cin>>dimension_x>>dimension_y;
    vector<vector<bool>>map_of_lost(dimension_y + 1, std::vector<bool> (dimension_x + 1, false));
    while (cin >> pos_x >> pos_y >> orientation) {
        string movimientos;
        cin >> movimientos;
        Robot robot(dimension_x, dimension_y, pos_x, pos_y, orientation);
        robot.Recorrer(movimientos,map_of_lost);
        robot.Imprimir_robot();
    }
        return 0;
}
