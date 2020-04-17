var LW=innerHeight/2.75;//white key lenght
var LB=LW/1.75;//black key length
var WW=innerWidth/21.5;//white key width
var WB=WW/2;// black key width
var White=[];//white keys
var keyLengthlopes=20;// how many white keys in each row
var lopes=innerHeight/14;// top of first row
var booty=(innerHeight/2)+lopes/2;// bottom of first row
var black=[];// black keys with no spaces
var twoThree=[];// black keys with two three orientation
var blackKeys=[2,4, null,7,9,11,null,14,16,null,19,21,23,null,26,28,null,31,33,35];
var whiteKeys=[1,3,5,6,8,10,12,13,15,17,18,20,22,24,25,27,29,30,32,34,36]
var keysPressed=[];
var count=0;
var wholeNote=100;
function setup(){
    createCanvas(innerWidth, innerHeight);
}

function draw(){
    background(51);
Keys();
Pressed();
text(count+' notes', 400,390);
text(keysPressed, 10,innerHeight/1.05);
}
function notes( color, numb, top){
    if(count%2==0){
if(color==0){
    if(top==0)
    keysPressed[count]=blackKeys[numb-1];
    else 
    keysPressed[count]=blackKeys[numb-1]+36;
}
else if(color==1){
    if(top==0)
    keysPressed[count]=whiteKeys[numb-1];
    else 
    keysPressed[count]=whiteKeys[numb-1] + 36;
}
else if(color==2){
if(top==0)
keysPressed[count]=36;
else 
keysPressed[count]=72;
}}
else
keysPressed[count]='wn';}

function Pressed(){

    if(mouseIsPressed){
         //black keys
    fill(200);
    if(mouseY>=lopes&&mouseY<=(lopes+LB)){
        for(let i=1;i<twoThree.length;i++){
    if(mouseX>twoThree[i]&&mouseX<(twoThree[i]+WB)){
rect(twoThree[i],lopes,WB,LB);
    }
}}
else if(mouseY>=booty&&mouseY<=(booty+LB)){
    for(let i=1;i<twoThree.length;i++){
if(mouseX>twoThree[i]&&mouseX<(twoThree[i]+WB)){
rect(twoThree[i],booty,WB,LB);
}
}}
else 
white();
 }
}

function mouseClicked(){
    if(mouseY>=lopes&&mouseY<=(lopes+LB)){
        for(let i=1;i<twoThree.length;i++){
    if(mouseX>twoThree[i]&&mouseX<(twoThree[i]+WB)){
notes(0, i, 0);
    }}
    count++;
}
    else if(mouseY>=booty&&mouseY<=(booty+LB)){
        for(let i=1;i<twoThree.length;i++){
    if(mouseX>twoThree[i]&&mouseX<(twoThree[i]+WB)){
        notes(0, i, 1);
    }
    }
    count++;
}
    else {
        if(mouseY>=lopes&&mouseY<=(lopes+LW)){//top row
        for(let i=0;i<White.length;i++){
            if(mouseX<=White[i]&&mouseX>=White[i-1]){
                    notes(1, i, 0);
            }}
        }
            if(mouseY>=booty&&mouseY<=(booty+LW)){//bottom row
                for(let i=0;i<White.length;i++){
                    if(mouseX<=White[i]&&mouseX>=White[i-1]){ 
                notes(1, i, 1);
                    }}
                }
        if(mouseY>=lopes&&mouseY<=(lopes+LW)){
         if(mouseX>White[20]){
            notes(2, 20, 0);
        }
          }
          if(mouseY>=booty&&mouseY<=(booty+LW)){
            if(mouseX>White[20]){
                notes(2, 20, 1);
            }
            }
            if((mouseY>=lopes&&mouseY<=(lopes+LW))||(mouseY>=booty&&mouseY<=(booty+LW))){
            count++;
    }
}}

function white(){
    fill(100);
    for(let i=0;i<White.length;i++){
    if(mouseX<=White[i]&&mouseX>=White[i-1]){
        if(mouseY>=lopes&&mouseY<=(lopes+LW)){//top row
rect(White[i-1],lopes,WW,LW);
    }
    if(mouseY>=booty&&mouseY<=(booty+LW)){//bottom row
        rect(White[i-1],booty,WW,LW);
            }
}
if(mouseY>=lopes&&mouseY<=(lopes+LW)){
 if(mouseX>White[20]){
rect(White[20],lopes,WW,LW);
}
  }
  if(mouseY>=booty&&mouseY<=(booty+LW)){
    if(mouseX>White[20]){
   rect(White[20],booty,WW,LW);}
     }
    }
}

function Keys(){
    for(let i=0;i<=keyLengthlopes;i++){
        fill(255);
        White[i]=i*WW;
    rect(White[i],lopes, WW, LW);
    fill(0);
    text(whiteKeys[i],White[i]+10,lopes+LW-10);}
    fill(0);
    
    for(let i=0;i<White.length;i++){
        if(i>0)
        black[i]=White[i]-(WB/2);
        else
        black[i]=0;
    if(i<3&&i>0){//2
        fill(0);
twoThree[i]=black[i];
        rect(black[i],lopes, WB, LB);
        fill(255);
        if(i==1){//text
            textSize(WB);
        text(2,black[i],lopes);
    }
        else if(i==2){
        text(4,black[i],lopes);}
    }

    else if(i>3&&i<7){//3
        fill(0);
        twoThree[i]=black[i];
        rect(black[i],lopes, WB, LB);
        fill(255);
        if(i==4){//text
        text(7,black[i],lopes);
    }
        else if(i==5){
        text(9,black[i],lopes);}
    else if(i==6){
        text(11,black[i],lopes);}
        }

    else if(i<10&&i>7){//2
        fill(0);
        twoThree[i]=black[i];
        rect(black[i],lopes, WB, LB);
        fill(255);
        if(i==8){//text
            textSize(WB);
        text(14,black[i],lopes);
    }
        else if(i==9){
        text(16,black[i],lopes);}
    }

    else if(i>10&&i<14){//3
        fill(0);
        twoThree[i]=black[i];
        rect(black[i],lopes, WB, LB);
        fill(255);
        if(i==11){//text
            text(19,black[i],lopes);
        }
            else if(i==12){
            text(21,black[i],lopes);}
        else if(i==13){
            text(23,black[i],lopes);}
    }
    else if(i<17&&i>14){//2
        fill(0);
        twoThree[i]=black[i];
        rect(black[i],lopes, WB, LB);
        fill(255);
        if(i==15){//text
            textSize(WB);
        text(26,black[i],lopes);
    }
        else if(i==16){
        text(28,black[i],lopes);}
    }
    else if(i>17&&i<21){//3
        fill(0);
        twoThree[i]=black[i];
        rect(black[i],lopes, WB, LB);
        fill(255);
        if(i==18){//text
            text(31,black[i],lopes);
        }
            else if(i==19){
            text(33,black[i],lopes);}
        else if(i==20){
            text(35,black[i],lopes);}
    }}
    //section 2
    for(let i=0;i<=keyLengthlopes;i++){
        fill(255);
    rect(White[i],booty, WW, LW);
    fill(0);
    text(whiteKeys[i]+36,White[i]+10,booty*1.65);}

    fill(0);
    for(let i=0;i<White.length;i++){
        fill(0);
        rect(twoThree[i],booty, WB, LB);
        fill(255);
        if(i<2)
        text(blackKeys[i]+36,black[i+1],booty);
        else if(i<6&&i>2)
        text(blackKeys[i]+36,black[i+1],booty);
    else if(i<9&&i>6)
        text(blackKeys[i]+36,black[i+1],booty);
        else if(i<13&&i>9)
        text(blackKeys[i]+36,black[i+1],booty);
        else if(i<16&&i>13)
        text(blackKeys[i]+36,black[i+1],booty);
        else if(i<20&&i>16)
        text(blackKeys[i]+36,black[i+1],booty);
    }
    

    }
