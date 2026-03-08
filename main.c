#include <stdio.h>
#include <raylib.h>
#define RAYGUI_IMPLEMENTATION
#include <raygui.h>

int main(void){
        //initing the window
        int x = 500;
        int y = 600;

        int cPressCount = 0;
        double firstPressTime = 0;

        InitWindow(x,y,"Calc");
        Image img = LoadImage("calc.png");
        Image bbbggm = LoadImage("bbbggm.png");
        ImageResize(&bbbggm,x,y);
        Texture2D girl = LoadTextureFromImage(bbbggm);

        if (girl.id == 0){
                DrawText("fail",40,40,10,WHITE);
        }

        SetWindowIcon(img);
        UnloadImage(img);
        SetTargetFPS(30);

        //a lot of bools lol
        bool typesec = false;
        bool clicked = false;
        bool num1 = false;
        bool num2 = false;
        bool drawc = false;
        bool error = false;
        bool end = false;
        bool showgirl = false;

        //Operators,numbers,result
        double first = 0;
        double second = 0;
        double result = 0;
        char op = ' ';

        //color for red
        Color myblack = (Color){237,170,227,255};
        Color myback = (Color){255,222,250,255};
        Color mygray = (Color){208,141,199,255};
        Color mylight = (Color){244,194,237,255};
        Color txt = (Color){199,79,181,255};

        while (!WindowShouldClose()) {
                BeginDrawing();
                ClearBackground(mylight);
                DrawRectangle(50,0,400,600,myblack);

                if (first == 1337 && second == 1337 && op=='-'){
                        showgirl = true;
                        first = 0;
                        second = 0;
                        result = 0;
                        op=' ';
                }

                if (showgirl){
                        DrawTexture(girl,0,0,WHITE);

                        if (GuiButton((Rectangle){50,y-50,400,50},"B")){
                                        showgirl = false;
                        }
                }

                //Drawing Text
                if (!showgirl){
                        if (end)DrawText(TextFormat("%.1f",result),300,43,30,txt);
                        if (drawc)DrawText(TextFormat("%c",op),320,43,30,txt);
                        if (clicked)DrawText("=",270,37,40,txt);
                        if (num2)DrawText(TextFormat("%.1f",second),300,43,30,txt);
                        if (num1)DrawText(TextFormat("%.1f",first),300,43,30,txt);
                        if (error)DrawText("Syntax Error!\n",170,43,30,txt);
                }

                //for mouse position
                //Vector2 mousepos = GetMousePosition();
                //printf("mouse x %f mouse y %f\n",mousepos.x,mousepos.y);

                //a lot of mumbo jumbo , ignore it.

                //red like
                GuiSetStyle(DEFAULT,TEXT_SIZE,50);
                GuiSetStyle(DEFAULT,BASE_COLOR_NORMAL,ColorToInt(mylight));
                GuiSetStyle(DEFAULT,BASE_COLOR_FOCUSED,ColorToInt(myblack));
                GuiSetStyle(DEFAULT,BASE_COLOR_PRESSED,ColorToInt(myblack));
                GuiSetStyle(DEFAULT,BORDER_COLOR_NORMAL,ColorToInt(mygray));
                GuiSetStyle(DEFAULT,BORDER_COLOR_FOCUSED,ColorToInt(mygray));
                GuiSetStyle(DEFAULT,BORDER_COLOR_PRESSED,ColorToInt(mygray));
                GuiSetStyle(DEFAULT,TEXT_COLOR_NORMAL,ColorToInt(txt));
                GuiSetStyle(DEFAULT,TEXT_COLOR_FOCUSED,ColorToInt(txt));
                GuiSetStyle(DEFAULT,TEXT_COLOR_PRESSED,ColorToInt(txt));

                if (!showgirl){
                        if (GuiButton((Rectangle){50,100,300,100},"C")){
                                clicked = false;
                                first = 0;
                                second = 0;
                                result = 0;
                                op = ' ';
                                num1=false;
                                num2=false;
                                drawc=false;
                                typesec=false;
                                error = false;
                                end = false;

                                double now = GetTime();

                                if (cPressCount == 0){
                                        firstPressTime = now;
                                }
                                cPressCount++;

                                if (now - firstPressTime > 1.0){
                                        cPressCount = 1;
                                        firstPressTime = now;
                                }
                                if (cPressCount >= 5){
                                        CloseWindow();
                                }
                        }
                        if (GuiButton((Rectangle){50,500,300,100}, "0") && !end) (typesec == true)  ? (second = second * 10 + 0,num2=true,drawc=false,error=false) : (first = first * 10 + 0,num1=true,error=false);

                        if (GuiButton((Rectangle){50,200,100,100}, "7") && !end) (typesec == true)  ? (second = second * 10 + 7,num2=true,drawc=false,error=false) : (first = first * 10 + 7, num1=true,error=false);
                        if (GuiButton((Rectangle){150,200,100,100}, "8") && !end) (typesec == true) ? (second = second * 10 + 8,num2=true,drawc=false,error=false) : (first = first * 10 + 8, num1=true,error=false);
                        if (GuiButton((Rectangle){250,200,100,100},"9") && !end) (typesec == true) ? (second = second * 10 + 9,num2=true,drawc=false,error=false) : (first = first * 10 + 9, num1=true,error=false);

                        if (GuiButton((Rectangle){50,300,100,100}, "4") && !end) (typesec == true)  ? (second = second * 10 + 4,num2=true,drawc=false,error=false) : (first = first * 10 + 4, num1=true,error=false);
                        if (GuiButton((Rectangle){150,300,100,100}, "5")&& !end) (typesec == true) ? (second = second * 10 + 5,num2=true,drawc=false,error=false) : (first = first * 10 + 5, num1=true,error=false);
                        if (GuiButton((Rectangle){250,300,100,100}, "6")&& !end) (typesec == true) ? (second = second * 10 + 6,num2=true,drawc=false,error=false) : (first = first * 10 + 6, num1=true,error=false);

                        if (GuiButton((Rectangle){50,400,100,100}, "1") && !end) (typesec == true)  ? (second = second * 10 + 1, num2=true, drawc=false,error=false) : (first = first * 10 + 1, num1=true,error=false);
                        if (GuiButton((Rectangle){150,400,100,100},"2") && !end) (typesec == true)  ? (second = second * 10 + 2, num2=true, drawc=false,error=false) : (first = first * 10 + 2, num1=true,error=false);
                        if (GuiButton((Rectangle){250,400,100,100}, "3") && !end) (typesec == true) ? (second = second * 10 + 3, num2=true, drawc=false,error=false) : (first = first * 10 + 3, num1=true,error=false);

                        if (GuiButton((Rectangle){350,100,100,100}, "*") && !end && !num2) (num1) ? (typesec=true,op='*',drawc=true,num1=false) : (op = ' ');
                        if (GuiButton((Rectangle){350,200,100,100}, "/") && !end && !num2) (num1) ? (typesec=true,op='/',drawc=true,num1=false) : (op = ' ');
                        if (GuiButton((Rectangle){350,300,100,100}, "+") && !end && !num2) (num1) ? (typesec=true,op='+',drawc=true,num1=false) : (op = ' ');
                        if (GuiButton((Rectangle){350,400,100,100}, "-") && !end && !num2) (num1) ? (typesec=true,op='-',drawc=true,num1=false) : (op = ' ');

                //Showing result
                if (GuiButton((Rectangle){350,500,100,100}, "=")){
                        //ops
                        num2 = false;
                        if(op == '+')(result = first + second);
                        if(op == '-')(result = first - second);
                        if(op == '/')(second == 0) ? (result = 0) : (result = first / second);
                        if(op == '*')(result = first * second);
                        typesec = false;//-> so we cant rewrite the second number

                        if (first > 0 && second == 0){
                                error = true;
                                end = false;
                                clicked = false;
                                first = 0;
                                second = 0;
                                result = 0;
                                op = false;
                                num1 = false;
                                num2 = false;
                                drawc = false;
                                typesec = false;
                        }
                        else{
                                clicked = true;
                                end = true;
                        }

                }
                }
                EndDrawing();
        }
        CloseWindow();
}
