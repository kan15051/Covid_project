#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct userinfo{
    char FirstName[100];
    char LastName[100];
    char UserName[100];
    char PassWord[100];
    char HouseNO[100];
    char Village[100];
    char Lane[100];
    char Road[100];
    char SubDistrict[100];
    char District[100];
    char Province[100];
    char PostalCode[10];
    int number;
    char date[100][2][100];
    double result[100];
}UserInfo;

typedef struct proinfo{
    int Noinfected;
    int NOtotal;
    double percen;
    char Firstname[1000][100];
    char Lastname[1000][100];
}Proinfo;

int GetUserInfo(UserInfo*);

void ShowUserInfo(UserInfo);

int CheckExist(char*);

void CreateAccout();

void OpenUserInfo(char*, UserInfo*);

int CheckPass(char*, char*);

void GetFilename(char*, char*);

int Login(char*);

void Logout(char*, int* );

void Dosurvey(char*);

double Checkans(char*);

void Uppro(UserInfo);

void Inipro(char* );

void Showpro(char* );

int main(){
    int status=0;
    UserInfo user;
    char username[100]="\0",command[100];
    printf("register        for account register\nlogin           for login\nlogout          for logout\nshowinfo        show user infomation\ndosurvey        to do COVID-19 survey\nexit            exit the program\nhelp            show command\nprovince        show province infomation\n");
    while(1){
        printf("Enter command: ");
        fgets(command,10,stdin);
        command[strlen(command)-1]='\0';
        system("cls");
        if(strcmp("help",command)==0){
            printf("register        for account register\nlogin           for login\nlogout          for logout\nshowinfo        show user infomation\nexit            exit the program\ndosurvey        to do COVID-19 survey\nhelp            show command\nprovince        show province infomation\n");
        }
        if(strcmp(command, "register")==0){
            CreateAccout();
        }
        else if(strcmp(command,"login")==0){
            status=Login(username);
        }
        else if(strcmp(command,"logout")==0){
            Logout(username,&status);
        }
        else if(strcmp(command,"showinfo")==0){
            if(status==1){
                OpenUserInfo(username,&user);
                ShowUserInfo(user);
            }
            else{
                printf("please login\n");
            }
        }
        else if(strcmp(command,"dosurvey")==0){
            if(status==1){
                Dosurvey(username);
                OpenUserInfo(username,&user);
                Uppro(user);
            }
            else{
                printf("please login\n");
            }
            
        }
        else if(strcmp(command,"province")==0){
            char pro[100];
            printf("Enter province name(start with capital letter and no spacebar): ");
            fgets(pro, 100, stdin);
            pro[strlen(pro)-1]='\0';
            Showpro(pro);
        }
        else if(strcmp(command,"exit")==0){
            system("git add --all");
            system("git commit -a");
            system("git push");
            return 0;
        }
    }
    return 0;
}

int GetUserInfo(UserInfo* User){
    char filename[100];
    printf("Enter Firstname: ");
    fgets(User->FirstName,sizeof(User->FirstName),stdin);//firstname
    User->FirstName[strlen(User->FirstName)-1]='\0';
    printf("Enter Lastname: ");
    fgets(User->LastName,100,stdin);//lastname
    User->LastName[strlen(User->LastName)-1]='\0';
    printf("Enter Username: ");
    fgets(User->UserName,100,stdin);//username
    User->UserName[strlen(User->UserName)-1]='\0';
    GetFilename(User->UserName, filename);
    while(CheckExist(filename)){
        int i;
        char temp[2];
        printf("Username is already used\n");
        printf("use another username(type 1) or login(type 2)\n");
        printf("Type your Number: ");
        scanf("%d",&i);
        if(i==1){
            printf("Enter Username: ");
            fgets(temp,2, stdin);
            fgets(User->UserName,100,stdin);//username
            User->UserName[strlen(User->UserName)-1]='\0';
            GetFilename(User->UserName, filename);
        }
        else{
            fgets(temp,2, stdin);
            return 0;
        }
    }
    printf("Enter Password: ");
    fgets(User->PassWord,100,stdin);//password
    User->PassWord[strlen(User->PassWord)-1]='\0';
    printf("Please Fill Your Adress\n");
    printf("House Number: ");
    fgets(User->HouseNO,100,stdin);//houseno.
    User->HouseNO[strlen(User->HouseNO)-1]='\0';
    printf("Village: ");
    fgets(User->Village,100,stdin);//village
    User->Village[strlen(User->Village)-1]='\0';
    printf("Lane: ");
    fgets(User->Lane,100,stdin);//lane
    User->Lane[strlen(User->Lane)-1]='\0';
    printf("Road: ");
    fgets(User->Road,100,stdin);//road
    User->Road[strlen(User->Road)-1]='\0';
    printf("Sub-district: ");
    fgets(User->SubDistrict,100,stdin);//subdistrict
    User->SubDistrict[strlen(User->SubDistrict)-1]='\0';
    printf("District: ");
    fgets(User->District,100,stdin);//district
    User->District[strlen(User->District)-1]='\0';
    printf("Province: ");
    fgets(User->Province,100,stdin);//province
    User->Province[strlen(User->Province)-1]='\0';
    printf("Postal Code: ");
    fgets(User->PostalCode,100,stdin);//postalcode
    User->PostalCode[strlen(User->PostalCode)-1]='\0';
    return 1;
}

void ShowUserInfo(UserInfo User){
    printf("Enter Firstname: ");
    puts(User.FirstName);
    printf("Enter Lastname: ");
    puts(User.LastName);
    printf("Enter Username: ");
    puts(User.UserName);
    printf("Enter Password: ");
    puts(User.PassWord);
    printf("Please Fill Your Adress\n");
    printf("House Number: ");
    puts(User.HouseNO);
    printf("Village: ");
    puts(User.Village);
    printf("Lane: ");
    puts(User.Lane);
    printf("Road: ");
    puts(User.Road);
    printf("Sub-district: ");
    puts(User.SubDistrict);
    printf("District: ");
    puts(User.District);
    printf("Province: ");
    puts(User.Province);
    printf("Postal Code: ");
    puts(User.PostalCode);
    for(int i=0; i<User.number; i++){
        int s=User.result[i];
        printf("# : %d\n",i+1);
        printf("Date: %s\n",User.date[i][0]);
        printf("Time: %s\n",User.date[i][1]);
        if(s<=24){
            printf("Result: Low risk\n");
        }
        else if(s<=49){
            printf("Result: medium risk\n");
        }
        else if(s<=74){
            printf("Result: high risk\n");
        }
        else if(75<=s){
            printf("Result: very high risk\n");
        }
        //printf("Result: %.2lf\n",User.result[i]);
    }
}

int CheckExist(char* filename){
    FILE *fptr;
    if(fptr=fopen(filename,"rb")){
        fclose(fptr);
        return 1;
    }
    else{
        return 0;
    }
}

void GetFilename(char* username, char* filename){
    strcpy(filename, username);
    strcat(filename, ".bin");
}

void CreateAccout(){
    UserInfo User;
    if(GetUserInfo(&User)){
        char FileName[100];
        GetFilename(User.UserName, FileName);
        FILE *fptr;
        fptr = fopen(FileName,"wb");
        fwrite(&User, sizeof(User), 1, fptr);
        printf("Create account successful\n");
        fclose(fptr);
    }
}

void OpenUserInfo(char* Username, UserInfo* User){
    char filename[100];
    FILE *fptr;
    GetFilename(Username, filename);
    fptr = fopen(filename, "rb");
    fread(User, sizeof(*User), 1, fptr);
    fclose(fptr);
}

int CheckPass(char* Username, char* Password){
    char Filename[100];
    UserInfo temp;
    FILE *fptr;
    GetFilename(Username, Filename);
    if(!CheckExist(Filename)){
        return 0;
    }
    fptr=fopen(Filename,"rb");
    fread(&temp,sizeof(temp),1,fptr);
    fclose(fptr);
    if(!strcmp(Username,temp.UserName)){
        if(!strcmp(Password, temp.PassWord)){
            return 1;
        }
        return 0;
    }
    else{
        return 0;
    }
}

int Login(char* Username){
    char username[100], password[100], temp[2];
    printf("************LOGIN************\n");
    printf("Enter Username: ");
    fgets(username,100,stdin);
    username[strlen(username)-1]='\0';
    printf("Enter Password: ");
    fgets(password,100,stdin);
    password[strlen(password)-1]='\0';
    if(CheckPass(username, password)){
        printf("Login successful\n");
        strcpy(Username,username);
        return 1;
    }
    else{
        printf("Username or Password is incorrect\n");
        return 0;
    }

}

void Logout(char* Username, int* status){
    if(*status==0){
        printf("Already Logout\n");
    }
    else{
        strcpy(Username,"\0");
        *status = 0 ;
        if(*status==0){
            printf("Logout successful\n");
        }
    }
}

void Dosurvey(char* username){
    UserInfo user;
    char filename[100],ans[100];
    FILE *fptr;
    double score=0;
    GetFilename(username, filename);
    fptr= fopen(filename, "rb");
    fread(&user,sizeof(user),1,fptr);
    fclose;
    printf("1.Have you been diagnosed with COVID-19 on the basis of test by a doctor/general pratitioner/other?(yes/no)\n");
    printf("Enter ans: ");
    fgets(ans,100,stdin);
    ans[strlen(ans)-1]='\0';
    while(Checkans(ans)==-1){
        printf("1.Have you been diagnosed with COVID-19 on the basis of test by a doctor/general pratitioner/other?(yes/no)\n");
        printf("Enter ans(please answer yes or no): ");
        fgets(ans,100,stdin);
        ans[strlen(ans)-1]='\0';
    }
    if(Checkans(ans)==1){
        printf("2.According to the result from diagnosing, Do you infect the COVID-19?(yes/no)\n");
        printf("Enter ans: ");
        fgets(ans,100,stdin);
        ans[strlen(ans)-1]='\0';
        while(Checkans(ans)==-1){
            printf("2.According to the result from diagnosing, Do you infect the COVID-19?(yes/no)\n");
            printf("Enter ans(please answer yes or no): ");
            fgets(ans,100,stdin);
            ans[strlen(ans)-1]='\0';
        }
        if(Checkans(ans)==1){
            printf("Very hisk risk\n");
            strcpy(user.date[user.number][0],__DATE__);
            strcpy(user.date[user.number][1],__TIME__);
            user.result[user.number]=100;
            user.number++;
            fptr=fopen(filename,"wb");
            fwrite(&user,sizeof(user), 1, fptr);
            fclose(fptr);
            return;
        }
        else if(Checkans(ans)==0){
            printf("low risk\n");
            strcpy(user.date[user.number][0],__DATE__);
            strcpy(user.date[user.number][1],__TIME__);
            user.result[user.number]=0;
            user.number++;
            fptr=fopen(filename,"wb");
            fwrite(&user,sizeof(user), 1, fptr);
            fclose(fptr);
            return;
        }
    }
    else{
        printf("Have you had one or more of following symptoms\n");
        printf("3.1 Fever (38.5 C)\n");
        printf("Enter ans (yes/no): ");
        fgets(ans,100,stdin);
        ans[strlen(ans)-1]='\0';
        while(Checkans(ans)==-1){
            printf("3.1 Fever (38.5 ํC)\n");
            printf("Enter ans(please answer yes or no): ");
            fgets(ans,100,stdin);
            ans[strlen(ans)-1]='\0';
        }
        score+=0.5*Checkans(ans)*1.175;
        printf("3.2 Cough\n");
        printf("Enter ans (yes/no): ");
        fgets(ans,100,stdin);
        ans[strlen(ans)-1]='\0';
        while(Checkans(ans)==-1){
            printf("3.2 Cough\n");
            printf("Enter ans(please answer yes or no): ");
            fgets(ans,100,stdin);
            ans[strlen(ans)-1]='\0';
        }
        score+=0.5*Checkans(ans)*3.134;
        printf("3.3 Be tired\n");
        printf("Enter ans (yes/no): ");
        fgets(ans,100,stdin);
        ans[strlen(ans)-1]='\0';
        while(Checkans(ans)==-1){
            printf("3.3 Be tired\n");
            printf("Enter ans(please answer yes or no): ");
            fgets(ans,100,stdin);
            ans[strlen(ans)-1]='\0';
        }
        score+=0.5*Checkans(ans)*6.072;
        printf("3.4 Trouble breathing\n");
        printf("Enter ans (yes/no): ");
        fgets(ans,100,stdin);
        ans[strlen(ans)-1]='\0';
        while(Checkans(ans)==-1){
            printf("3.4 Trouble breathing\n");
            printf("Enter ans(please answer yes or no): ");
            fgets(ans,100,stdin);
            ans[strlen(ans)-1]='\0';
        }
        score+=0.5*Checkans(ans)*7.983;
        printf("3.5 Muscle pain/ joint pain\n");
        printf("Enter ans (yes/no): ");
        fgets(ans,100,stdin);
        ans[strlen(ans)-1]='\0';
        while(Checkans(ans)==-1){
            printf("3.5 Muscle pain/ joint pain\n");
            printf("Enter ans(please answer yes or no): ");
            fgets(ans,100,stdin);
            ans[strlen(ans)-1]='\0';
        }
        score+=0.5*Checkans(ans)*8.325;
        printf("3.6 Sore throat\n");
        printf("Enter ans (yes/no): ");
        fgets(ans,100,stdin);
        ans[strlen(ans)-1]='\0';
        while(Checkans(ans)==-1){
            printf("3.6 Sore throat\n");
            printf("Enter ans(please answer yes or no): ");
            fgets(ans,100,stdin);
            ans[strlen(ans)-1]='\0';
        }
        score+=0.5*Checkans(ans)*8.423;
        printf("3.7 Headache\n");
        printf("Enter ans (yes/no): ");
        fgets(ans,100,stdin);
        ans[strlen(ans)-1]='\0';
        while(Checkans(ans)==-1){
            printf("3.7 Headache\n");
            printf("Enter ans(please answer yes or no): ");
            fgets(ans,100,stdin);
            ans[strlen(ans)-1]='\0';
        }
        score+=0.5*Checkans(ans)*8.423;
        printf("3.8 Shiver\n");
        printf("Enter ans (yes/no): ");
        fgets(ans,100,stdin);
        ans[strlen(ans)-1]='\0';
        while(Checkans(ans)==-1){
            printf("3.8 Shiver\n");
            printf("Enter ans(please answer yes or no): ");
            fgets(ans,100,stdin);
            ans[strlen(ans)-1]='\0';
        }
        score+=0.5*Checkans(ans)*8.423;
        printf("3.9 Be squeamish\n");
        printf("Enter ans (yes/no): ");
        fgets(ans,100,stdin);
        ans[strlen(ans)-1]='\0';
        while(Checkans(ans)==-1){
            printf("3.9 Be squeamish\n");
            printf("Enter ans(please answer yes or no): ");
            fgets(ans,100,stdin);
            ans[strlen(ans)-1]='\0';
        }
        score+=0.5*Checkans(ans)*8.717;
        printf("3.10 Stuffed nose\n");
        printf("Enter ans (yes/no): ");
        fgets(ans,100,stdin);
        ans[strlen(ans)-1]='\0';
        while(Checkans(ans)==-1){
            printf("3.10 Stuffed nose\n");
            printf("Enter ans(please answer yes or no): ");
            fgets(ans,100,stdin);
            ans[strlen(ans)-1]='\0';
        }
        score+=0.5*Checkans(ans)*9.305;
        printf("3.11 Diarrhea\n");
        printf("Enter ans (yes/no): ");
        fgets(ans,100,stdin);
        ans[strlen(ans)-1]='\0';
        while(Checkans(ans)==-1){
            printf("3.11 Diarrhea\n");
            printf("Enter ans(please answer yes or no): ");
            fgets(ans,100,stdin);
            ans[strlen(ans)-1]='\0';
        }
        score+=0.5*Checkans(ans)*9.305;
        printf("3.12 Coughing up blood\n");
        printf("Enter ans (yes/no): ");
        fgets(ans,100,stdin);
        ans[strlen(ans)-1]='\0';
        while(Checkans(ans)==-1){
            printf("3.12 Coughing up blood\n");
            printf("Enter ans(please answer yes or no): ");
            fgets(ans,100,stdin);
            ans[strlen(ans)-1]='\0';
        }
        score+=0.5*Checkans(ans)*9.403;
        printf("3.13 Red eye(inflammation)\n");
        printf("Enter ans (yes/no): ");
        fgets(ans,100,stdin);
        ans[strlen(ans)-1]='\0';
        while(Checkans(ans)==-1){
            printf("3.13 Red eye(inflammation)\n");
            printf("Enter ans(please answer yes or no): ");
            fgets(ans,100,stdin);
            ans[strlen(ans)-1]='\0';
        }
        score+=0.5*Checkans(ans)*9.696;
        printf("3.14 Unable to smell\n");
        printf("Enter ans (yes/no): ");
        fgets(ans,100,stdin);
        ans[strlen(ans)-1]='\0';
        while(Checkans(ans)==-1){
            printf("3.14 Unable to smell\n");
            printf("Enter ans(please answer yes or no): ");
            fgets(ans,100,stdin);
            ans[strlen(ans)-1]='\0';
        }
        score+=0.5*Checkans(ans)*0.01;
        printf("3.15 Unable to taste\n");
        printf("Enter ans (yes/no): ");
        fgets(ans,100,stdin);
        ans[strlen(ans)-1]='\0';
        while(Checkans(ans)==-1){
            printf("3.15 Unable to taste\n");
            printf("Enter ans(please answer yes or no): ");
            fgets(ans,100,stdin);
            ans[strlen(ans)-1]='\0';
        }
        score+=0.5*Checkans(ans)*0.01;
        printf("3.16 Red eye\n");
        printf("Enter ans (yes/no): ");
        fgets(ans,100,stdin);
        ans[strlen(ans)-1]='\0';
        while(Checkans(ans)==-1){
            printf("3.16 Red eye\n");
            printf("Enter ans(please answer yes or no): ");
            fgets(ans,100,stdin);
            ans[strlen(ans)-1]='\0';
        }
        score+=0.5*Checkans(ans)*0.01;
        printf("3.17 Canker\n");
        printf("Enter ans (yes/no): ");
        fgets(ans,100,stdin);
        ans[strlen(ans)-1]='\0';
        while(Checkans(ans)==-1){
            printf("3.17 Canker\n");
            printf("Enter ans(please answer yes or no): ");
            fgets(ans,100,stdin);
            ans[strlen(ans)-1]='\0';
        }
        score+=0.5*Checkans(ans)*0.01;
        printf("4.(abroad) Have you ever abroad to high-risk country within 1 month\n");
        printf("Enter ans (yes/no): ");
        fgets(ans,100,stdin);
        ans[strlen(ans)-1]='\0';
        while(Checkans(ans)==-1){
            printf("4.(abroad) Have you ever abroad to high-risk country within 1 month\n");
            printf("Enter ans(please answer yes or no): ");
            fgets(ans,100,stdin);
            ans[strlen(ans)-1]='\0';
        }
        score+=Checkans(ans)*50;
        if(Checkans(ans)==0){
            printf("5.(abroad) Have you ever abroad to low-risk country within 1 month\n");
            printf("Enter ans (yes/no): ");
            fgets(ans,100,stdin);
            ans[strlen(ans)-1]='\0';
            while(Checkans(ans)==-1){
            printf("4.(abroad) Have you ever abroad to high-risk country within 1 month\n");
            printf("Enter ans(please answer yes or no): ");
            fgets(ans,100,stdin);
            ans[strlen(ans)-1]='\0';
            }
            score+=30;
            if(Checkans(ans)==0){
                printf("6(In country) Have you came from or stayed at are where someone is infected\n");
                printf("Enter ans (yes/no): ");
                fgets(ans,100,stdin);
                ans[strlen(ans)-1]='\0';
                while(Checkans(ans)==-1){
                printf("6(In country) Have you came from or stayed at are where someone is infected\n");
                printf("Enter ans(please answer yes or no): ");
                fgets(ans,100,stdin);
                ans[strlen(ans)-1]='\0';
                }
                if(Checkans(ans)==1){
                    printf("6.1 Have you worked at state quarantine or local quarantine\n");
                    printf("Enter ans (yes/no): ");
                    fgets(ans,100,stdin);
                    ans[strlen(ans)-1]='\0';
                    while(Checkans(ans)==-1){
                    printf("6.1 Have you worked at state quarantine or local quarantine\n");
                    printf("Enter ans(please answer yes or no): ");
                    fgets(ans,100,stdin);
                    ans[strlen(ans)-1]='\0';
                    }
                    if(Checkans(ans)==1){
                        score+=40;
                        printf("6.1.1 Have you contact with a confirmed Infected person\n");
                        printf("Enter ans (yes/no): ");
                        fgets(ans,100,stdin);
                        ans[strlen(ans)-1]='\0';
                        while(Checkans(ans)==-1){
                        printf("6.1.1 Have you contact with a confirmed Infected person\n");
                        printf("Enter ans(please answer yes or no): ");
                        fgets(ans,100,stdin);
                        ans[strlen(ans)-1]='\0';
                        }
                        score+=Checkans(ans)*10;
                    }
                    printf("6.2 Are you a  medical personnel(hospital, clinic, disease investigation team, pharmacy)\n");
                    printf("Enter ans (yes/no): ");
                    fgets(ans,100,stdin);
                    ans[strlen(ans)-1]='\0';
                    while(Checkans(ans)==-1){
                        printf("6.2 Are you a  medical personnel(hospital, clinic, disease investigation team, pharmacy)\n");
                        printf("Enter ans(please answer yes or no): ");
                        fgets(ans,100,stdin);
                        ans[strlen(ans)-1]='\0';
                    }
                    score+=Checkans(ans)*30;
                    printf("6.3 Have you ever been to crowded place (market, hospital, the mall, public transport) with in 1 month\n");
                    printf("Enter ans (yes/no): ");
                    fgets(ans,100,stdin);
                    ans[strlen(ans)-1]='\0';
                    while(Checkans(ans)==-1){
                        printf("6.3 Have you ever been to crowded place (market, hospital, the mall, public transport) with in 1 month\n");
                        printf("Enter ans(please answer yes or no): ");
                        fgets(ans,100,stdin);
                        ans[strlen(ans)-1]='\0';
                    }
                    score+=Checkans(ans)*20;
                    printf("6.4 In the place you go often, people close to you have symptom of 5 people or more\n");
                    printf("Enter ans (yes/no): ");
                    fgets(ans,100,stdin);
                    ans[strlen(ans)-1]='\0';
                    while(Checkans(ans)==-1){
                        printf("6.4 In the place you go often, people close to you have symptom of 5 people or more\n");
                        printf("Enter ans(please answer yes or no): ");
                        fgets(ans,100,stdin);
                        ans[strlen(ans)-1]='\0';
                    }
                    score+=Checkans(ans)*15;
                }
            }
        }
        if(score<=24){
            printf("Low risk\n");
        }
        else if(score<=49){
            printf("medium risk\n");
        }
        else if(score<=74){
            printf("high risk\n");
        }
        else if(75<=score){
            printf("very high risk\n");
        }
        strcpy(user.date[user.number][0],__DATE__);
        strcpy(user.date[user.number][1],__TIME__);
        user.result[user.number]=score;
        user.number++;
        fptr=fopen(filename,"wb");
        fwrite(&user,sizeof(user), 1, fptr);
        fclose(fptr);
        return ;
    }
}

double Checkans(char* ans){
    for(int i=0; i<strlen(ans)-1;i++){
        ans[i]=tolower(ans[i]);
    }
    if(strcmp(ans,"yes")==0){
        return 1.0;
    }
    else if(strcmp(ans,"no")==0){
        return 0.0;
    }
    else
        return -1.0;
}

void Uppro(UserInfo user){
    Proinfo province;
    char filename[100];
    FILE *fptr;
    GetFilename(user.Province, filename);
    fptr = fopen(filename, "rb");
    fread(&province, sizeof(province), 1, fptr);
    fclose(fptr);
    char name1[100];
    char name2[100];
    strcpy(name1,user.FirstName);
    strcpy(name2,user.LastName);
    for(int i=-1; i<province.Noinfected; i++){
        if(!(strcmp(name1,province.Firstname[i])&&strcmp(name2,province.Lastname[i]))){
            break;
        }
        if(i==province.Noinfected-1){
            strcpy(province.Firstname[i+1],name1);
            strcpy(province.Lastname[i+1],name2);
            province.Noinfected++;
            province.percen=((double)province.Noinfected/(double)province.NOtotal)*100;
        }
    }
    fptr = fopen(filename, "wb");
    fwrite(&province, sizeof(province), 1,fptr);
    fclose(fptr);
}

void Inipro(char* pro){
    Proinfo province;
    char filename[100];
    FILE *fptr;
    GetFilename(pro,filename);
    province.Noinfected=0;
    province.NOtotal=1000000;
    province.percen=0;
    fptr = fopen(filename, "wb");
    fwrite(&province, sizeof(province), 1, fptr);
    fclose(fptr);
}

void Showpro(char* pro){
    Proinfo province;
    char filename[100];
    FILE *fptr;
    GetFilename(pro,filename);
    fptr=fopen(filename, "rb");
    fread(&province, sizeof(province), 1, fptr);
    fclose(fptr);
    printf("Province: %s\n",pro);
    printf("Number of infected people: %d\n", province.Noinfected);
    printf("Total of number who live in province: %d\n", province.NOtotal);
    printf("Percentage of infected people: %.6lf\n", province.percen);
    /*
    for(int i=0; i<province.Noinfected; i++){
        printf("NO : %d\n", i+1);
        printf("Firstname: %s\n", province.Firstname[i]);
        printf("Lastname: %s\n", province.Lastname[i]);
    }
    */
}
