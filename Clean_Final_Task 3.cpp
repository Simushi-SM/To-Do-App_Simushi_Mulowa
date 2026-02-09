#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// Structure Declaration
struct Park{string name;bool isKill; };

//Function Prototypes
void ShowTasks(vector<Park> &animals);
void Mark_Task(vector<Park> &animals,int &place,int &mark);
void Unmark_Task(vector<Park> &animals,int &place,int &mark);
void Delete_Task(vector<Park> &animals,int &position,int &getrid);
void Add_Task(vector<Park>&animals, string &input, string name, bool isKill);
string status(bool isKill);

//File System Function Prototypes
void Load_File(vector<Park> &animals); //Reading the AVAILABLE data which is in the File
void SaveTo_File(vector<Park> &animals); //Writing the EDITED data INTO the File

int main(){


cout<<"            Made by Simushi Mulowa a.k.a Mularts "<<endl;
char i;
 for(i=1;i<=68;i++){
  cout<< "=";
 }
 cout<<endl;
 cout<<" MY TO-DO-LIST APPLICATION (control it using numbers from the Menu) "<<endl;
 for(i=1;i<=68;i++){
  cout<< "=";
 }
 cout<<endl;


 vector<Park>animals; //creating a Vector "animals" which has swallowed a Structure "Park"

 Load_File(animals); //Reading or Loading contents of the File Putting them INTO the Struct "Park" then to vector "animals"

int option;
do{

cout<<"1.Create a Task "<<endl;
cout<<"2.View my created Tasks "<<endl;
cout<<"3.Mark a Task as Completed "<<endl;
cout<<"4.Unmark a Task as uncompleted "<<endl;
cout<<"5.Delete a Task"<<endl;
cout<<"6.Exit "<<endl;

 cout<<"What would You like to do ? "<<endl;
 cin>> option;
  if(cin.fail()){ //The "cin.fail()" checks whether the data-type from the input of the user matches the data-type of the variable receiving the input
   cin.clear();    //if the data-type recieved was wrong,the above line blocks ALL "cin's" and "cin.clear() unblocks them again
   cin.ignore(1000,'\n');  //"cin.ignore(1000,'\n')" now flashes out the dirty unmatching data leaving the "cin" clean again

    cout<<"Thats an invalid input!Please enter a number from the Menu"<<endl;

  option = 0; //This now initializes option to a new fresh variable that should ALWAYS be a digit behind the starting position of the Menu
   }          // as to reset it safely

//Authority transfer from Park Structure to "hunt" transporter(object)
Park hunt;

//The switch "Muscles"
switch(option){
    case 1:{//Adding a Task
string input,name;
bool isKill;
Add_Task(animals,input,name,isKill);
break;
}

case 2:{//Printing Everything
ShowTasks(animals);
break;
}

case 3:{//Marking a Task as Done
   int place,mark; //inside main,old variables have to be re-declared to get permission to be used inside the "int main()"
   Mark_Task(animals,place,mark);
break;
}

case 4:{//Unmarking a Task as Not Done
    int place,mark;////inside main,old variables have to be re-declared to get permission to be used inside the "int main()"
    Unmark_Task(animals,place,mark);
break;
}

case 5:{//Deleting a Task
   int position,getrid;
   Delete_Task(animals,position,getrid);
break;
}

case 6:{//Saving to File on Exiting the Menu

    SaveTo_File(animals); //Though not necessary because every manipulation is saved imediettely
                          //meaning this Function call is irrelevant and programme can work as required to standard without the call to save!
    cout<<"Have a Productive Day Thanks for Planning with us!"<<endl;
break;
}

  default:{ cout<<"Invalid option! Please  choose one option between 1 to 5 "<<endl;
 break;
   }

  }
}
 while(option !=6 );


 return 0;
}


//---------------------------------------------------------------------------------------------------------------
// THE WORKING BACKGROUND OF FUNCTIONS AS MAIN "VITAL ORGANS"
//---------------------------------------------------------------------------------------------------------------
// FUNCTION for [Done] or [Not Done] using the stupid Boolean
 string status(bool isKill){
    return isKill ? "[Done]" : "[Not Done]";
}

//---------------------------------------------------------------------------------------------------------------
//FUNCTION for Printing Everything
 void ShowTasks(vector<Park> &animals){
  string cage = "Your Tasks are: ";

     if(!animals.empty()){
        cout<<cage<<"1."<<animals[0].name<<status(animals[0].isKill)<<endl;
    }
    else{
        cout<<"Sorry you have not created any Task yet,Create a Task by selecting option 1 FIRST"<<endl<<endl;
     }

   for(int x = 0; x < animals.size(); x++){
        if(animals[x].name == animals[0].name){
         continue;
        }
       cout<< string(cage.length(),' ')<<x+1<<"."<<animals[x].name<<status(animals[x].isKill)<<endl;
       }
 cout<<endl;
 }


 //----------------------------------------------------------------------------------------------------------------------------------
//FUNCTION for Marking by Index
void Mark_Task(vector<Park> &animals,int &place,int &mark){

    if(animals.empty()){

      cout<<" Invalid input,Please select a Task which you have already Created "<<endl;
      cout<<" Select Option 1 to Create your Task "<<endl;
        cin.ignore();
cout<<endl;
       return;
    }
    else{
   cout<<"Which Task do you want to mark ?"<<endl;
   cin>>place;
    mark = place - 1;

   if(mark>=0 && mark<animals.size()){

    animals[mark].isKill = 1; // 1 = true , 0 = false

   SaveTo_File(animals); //Saving the change directly to the File

    //Print Everything
    ShowTasks(animals);

   }

    }
 cout<<endl;
  }


//-------------------------------------------------------------------------------------------------------------------------------
//FUNCTION for Unmarking by Index
void Unmark_Task(vector<Park> &animals,int &place,int &mark){

    if(animals.empty()){

      cout<<" Invalid input,Please select a Task which you have already Created "<<endl;
      cout<<" Select Option 1 to Create your Task "<<endl;
        cin.ignore();
cout<<endl;
       return;
    }
    else{
   cout<<"Which Task do you want to Unmark ?"<<endl;
   cin>>place;
    mark = place - 1;

   if(mark>=0 && mark<animals.size()){

    animals[mark].isKill = 0; // 0 = false , true = 1

   SaveTo_File(animals); //Saving the change directly to the File

    //Print Everything
    ShowTasks(animals);

   }
    }
  }


//-------------------------------------------------------------------------------------------------------------------------------
//FUNCTION for Deleting a Task

  void Delete_Task(vector<Park> &animals,int &position,int &getrid){

    if(animals.empty()){

      cout<<" Invalid input,Please select a Task which you have already Created "<<endl;
      cout<<" Select Option 1 to Create your Task "<<endl;
        cin.ignore();
cout<<endl;
       return;
    }
    else{

   cout<<"Choose the number of the Task to Delete"<<endl;
   cin>>position;
   getrid = position - 1;

   if(getrid>=0 && getrid<animals.size()){
    animals.erase(animals.begin() + getrid);
    cout<<"Task successfully deleted \n";
   }

 }
 SaveTo_File(animals); //Saving the change directly to the File

 cout<<endl;

//Print Everything
   ShowTasks(animals);
  }


   //--------------------------------------------------------------------------------------------------------------------------
   //FUNCTION for Adding a Task
   void Add_Task(vector<Park>&animals, string &input, string name, bool isKill){
       Park hunt;
    cout<<"Enter the name of a Task you want To Do: ";
    cin.ignore();
    getline(cin,input);

    if(input.empty()){
        cout<<"You have not written anything at all please type something before you can do anything to it"<<endl;
    }
    else{
    //Feeding the variable "input" which feeds the Structure variable called "name"
    hunt.name = input;
    hunt.isKill = 0; // 0 = false , 1 = true

   animals.push_back(hunt); //The "hunt" Transporter finally feeds everything in the vector "animals"

  SaveTo_File(animals); //Saving the change directly to the File

   //Print Everything
   ShowTasks(animals);
    }
 }


 //----------------------------------------------------------------------------------------------------------------------------
 // The File System
// Reading from File

  //FUNCTION for Loading
 void Load_File(vector<Park> &animals){

  Park poacher; //Park gives transportation Authority to poacher

  //Reading or Extracting Data from the File

  ifstream Extract("Backbone.txt");

   if(!Extract.is_open()){
    cout<<"File did not open!"<<endl;
   }
   else{
    cout<<"File Openned Successfully! meaning your Tasks will be Automatically saved"<<endl;
    cout<<endl;
   }

  animals.clear(); //Cleaning the vector or making it Empty before ANYTHING is added to it i call it,"Purification"

  while(getline(Extract,poacher.name )){ //Moving data line by line from "Extract" valve into name with transporter poacher
    Extract>>poacher.isKill;
    Extract.ignore();
    animals.push_back(poacher);
   }
 }

// FUNCTION for Saving to File-------------------------------------------------------------------------------------------------------

//Writing Data to the File

void SaveTo_File(vector<Park> &animals){

 ofstream InjectFile("Backbone.txt");

  //checking if the File is Open or not
  if(!InjectFile.is_open()){
    cout<<" The File has failed to open its Mouth ai"<<endl;
     return;
  }

  for(Park &poacher : animals){ //since animals is swallowing a "Park" the transporter "poacher is the true mover of Task names and statuses
    InjectFile<<poacher.name<<endl<<poacher.isKill<<endl;  //The actual injecting of Tasks from the Park from animals INTO the inlet-valve "InjectFile"
  }

 InjectFile.close(); //closing the Task/data inlet valve
}







