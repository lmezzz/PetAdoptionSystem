#include <iostream>
#include <string>
using namespace std;

class My_pet
{
    string HealthStatus;
    int HungerLevel;
    int HappinessLevel;
    string SpecialSkills[5];
    int skills;
    int health_metre;

    void Update_Health()
    {
        if (HungerLevel >= 3 || HappinessLevel <= 5)
        {
            HealthStatus = "Sick";
            cout << "Health Update : Sick"<<endl;
        }
        if (HungerLevel < 3 || HappinessLevel > 5)
        {
            HealthStatus = "Healthy";
            cout << "Health Update : Healthy"<<endl;
        }
        if (HungerLevel > 2)//this will 
        {
            if (HappinessLevel > 0)
            {
                HappinessLevel--;
                cout<<"Your Dog is Hungry"<<endl;
            }
            else{
                cout<<"FEED YOUR PET"<<endl;
            }
            
            
        }
        
    }
    void Update_Happiness()
    {
        if (HappinessLevel < 10)
        {
            HappinessLevel++;
        }
        Update_Health();
    }
    public:
    My_pet()
    {
        HealthStatus = "healthy";
        HungerLevel = 0;
        HappinessLevel = 10;
        for (int i = 0; i < 5; i++)
        {
            SpecialSkills[i] = "\0";
        }
        skills = 0;
    }

    void Add_Skiils()
    {
        if (skills < 5)
        {
            if (HungerLevel < 9)
            {
                cout << "enter the name of skill u want to add" << endl;
                cin >> SpecialSkills[skills];
                skills++;
                HungerLevel += 2;
            }
            else
            {
                cout << "pet is too Hungry feed It first"<<endl;
            }
        }
        else{
            cout<<"cant make it learn more skills"<<endl;
        }

        Update_Health();
    }
    
    void Feed()
    {
        if (HungerLevel == 0)
        {
            cout << "your pet is already full"<<endl;
        }
        else
        {
            HungerLevel--;
        }
        Update_Health();
    }
    void Walk()
    {
        if (HungerLevel < 10)
        {
            if (HappinessLevel < 10)
            {
                HappinessLevel++;
                HungerLevel++;
            }
            else
            {
                HungerLevel++;
                cout << "Dog had a great Walk"<<endl;
            }
        }
        else
        {
            cout << "Feed your pet first" << endl;
        }
        Update_Health();
    }
    void pet()
    {
        if (HappinessLevel < 10)
        {
            HappinessLevel++;
        }
        else
        {
            cout << "Pet is already To Happy" << endl;
        }
        Update_Health();
    }
    void Display_info(){
        cout<<"Pet Status"<<endl;
        cout<<"HappinessLevel :"<<HappinessLevel<<endl;
        cout<<"HungerLevel :"<<HungerLevel<<endl;
        cout<<"Health Status :"<<HealthStatus<<endl;
        for (int i = 0; i < skills; i++)
        {
            cout<<"skill No."<<i+1<<" :"<<SpecialSkills[i]<<endl;
        }
        
    }
};

class Adopter{
    My_pet *pet_arr[5];
    int pets;
    string AdopterName;
    string AdopterMobileNo;

    public:

    Adopter(string Name , string Number){
        AdopterName = Name;
        AdopterMobileNo =   Number;
        pets = 0;
        for (int i = 0; i < 5; i++)
        {
            pet_arr[i] = new My_pet;
        }
        
    }
    void Adopt_pet(My_pet &obj){
        if (pets < 5)
        {
           pet_arr[pets] = &obj;
           pets++;
        }
        else{
            cout<<"pet limit reached"<<endl;
        }
    }
    void Return_pet(){
        int pet_no;
        cout<<"enter Which Pet u want To return"<<endl;
        cin>>pet_no;

        pet_no--;
        if (pet_no < pets)
        {
           for (int i = pet_no; i < 5; i++)
        {
            *pet_arr[i] = *pet_arr[i+1];

        }
        pets--;
        }
        else{
            cout<<"enter a Valid Pet No."<<endl;
        }
        
        
        
    }
    void Pet(){
        int index;
        cout<<"enter the No of pet u want to Pet";
        cin>>index;
        index--;
        if (index < pets)
        {
            pet_arr[index]->pet();
        }
        else{
            cout<<"enter a Valid Pet No."<<endl;
        }
        
    }
    void Peed(){
        int index;
        cout<<"enter the No of pet u want to Feed";
        cin>>index;
        index--;
        if (index < pets)
        {
            pet_arr[index]->Feed();
        }
        else{
            cout<<"enter a Valid Pet No."<<endl;
        }
        
    }
    void Palk(){
        int index;
        cout<<"enter the No of pet u want to take for a walk";
        cin>>index;
        index--;
        if (index < pets)
        {
            pet_arr[index]->Walk();
        }
        else{
            cout<<"enter a Valid Pet No."<<endl;
        }
        
    }
    void Pet_skills(){
        int index;
        cout<<"enter the No of pet u want to train";
        cin>>index;
        index--;
        if (index < pets)
        {
            pet_arr[index]->Add_Skiils();
        }
        else{
            cout<<"enter a Valid Pet No."<<endl;
        }
        
    }
    void Display(){
        for (int i = 0; i < pets; i++)
        {
            pet_arr[i]->Display_info();
        }
        
    }

};

int main() {
    bool isRunning = true;
    My_pet dogs[10];
    int petAvailability[10] = {1}; 

    Adopter Ayaan("Ayaan Raza", "XYZ");

    while (isRunning) {
        cout << "\n========== Pet Adoption System ==========\n";
        cout << "1. Adopt New Pet\n2. Return Pet\n3. Feed Pet\n4. Take Pet for a Walk\n5. Pet Your Pet\n";
        cout << "6. Train Your Dog\n7. Display all Pets' Info\n8. Exit\n";
        cout << "=========================================\n";
        cout << "Enter your choice: ";

        int userChoice;
        cin >> userChoice;

        switch (userChoice) {
            case 1: {
                int petNo;
                cout << "Enter the Pet you want to adopt (1-10): ";
                cin >> petNo;
                petNo--;

                if (petNo >= 0 && petNo < 10 && petAvailability[petNo] == 1) {
                    Ayaan.Adopt_pet(dogs[petNo]);
                    petAvailability[petNo] = 0; 
                    cout << "Adopted a new pet!\n";
                } else {
                    cout << "Invalid choice or pet already adopted. Please choose again.\n";
                }
                break;
            }
            case 2: {
                Ayaan.Return_pet();
                break;
            }
            case 3: {
                Ayaan.Peed();
                break;
            }
            case 4: {
                Ayaan.Palk();
                break;
            }
            case 5: {
                Ayaan.Pet();
                break;
            }
            case 6: {
                Ayaan.Pet_skills();
                break;
            }
            case 7: {
                Ayaan.Display();
                break;
            }
            case 8: {
                isRunning = false;
                cout << "Exiting the Pet Adoption System. Goodbye!\n";
                break;
            }
            default: {
                cout << "Invalid choice. Please choose a valid option.\n";
                break;
            }
        }
    }

    return 0;
}