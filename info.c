#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "menus.h"


void get_info()
{
    clear_screen();
    printf("\t\tFREQUENTLY ASKED QUESTIONS(FAQ)\n\n");

    printf("1.WHAT IS KRISHI-DARSHAN?\n\n");
    printf("\tKrishi-Darshan is a console-based agriculture management system designed\n");
    printf("\tto streamline data handling across all stakeholders-farmers, field-agents,\n");
    printf("\tand administrators. It centralizes farmer profiles, land records, crop\n");
    printf("\tcycles, loan/subsidy applications, and general farming guidelines.\n\n");

    printf("2. WHO CAN I USE KRISHI-DARSHAN?\n\n");
    printf("\t1.Farmers: Register, manage profiles, apply for loans/subsidies, and track crop cycles.\n");
    printf("\t2.Field Agents: Inspect assigned fields, upload reports, and manage schedules.\n");
    printf("\t3.Admins: Oversee all data, approve applications, configure schemes, and generate analytics.\n\n");

    printf("3.HOW DO I REGISTER AS A FARMER?\n\n");
    printf("\t1.From the welcome menu, select Register.\n");
    printf("\t2.Fill in personal, contact, and bank details.\n");
    printf("\t3.Submit and await admin approval (you'll receive a notification once activated).\n\n");

    printf("4.HOW DO I LOG IN?\n\n");
    printf("\t1.Select Login at the main prompt.\n");
    printf("\t2.Choose your role (Farmer / Agent / Admin).\n");
    printf("\t3.Enter your registered username and password.\n");
    printf("\t4.If you forget your password, use Forgot Password to reset via registered email.\n\n");

    printf("5.WHAT FUNCTIONALITIES ARE AVAILABLE TO THE FARMERS?\n\n");
    printf("\t1.Profile Management: View/update personal, bank, and contact details.\n");
    printf("\t2.Land Parcels: Add, view, or remove parcels.\n");
    printf("\t3.Applications: Submit and track loan, subsidy, or scheme requests.\n");
    printf("\t4.Crop Tracker: Record planting dates, growth stages, and harvest schedules.\n");
    printf("\t5.Farming Info: Access general guidelines and best practices via the integrated AI bot.\n\n");

    printf("6.HOW DO FIELD AGENTS MANAGE THEIR ASSIGNMENTS?\n\n");
    printf("\t1.Assigned Parcels List: View all parcels under your supervision.\n");
    printf("\t2.Report Management: Create, update, or delete inspection reports.\n");
    printf("\t3.Scheduling: Plan visits and update farmer parcel statuses.\n");
    printf("\t4.Notifications: Receive automatic alerts for pending reports or status changes.\n\n");

    printf("7.WHAT ADMINIDRATIVE CONTROLS AFE PROVIDED?\n\n");
    printf("\t1.User Management: Add, view, update, or remove farmer and agent accounts.\n");
    printf("\t2.Parcel Management: Oversee all land records and parcel assignments.\n");
    printf("\t3.Scheme Configuration: Define or adjust loan, subsidy, and scheme parameters.\n");
    printf("\t4.Request Approvals: Review and act on incoming applications.\n");
    printf("\t5.Analytics: Generate reports on application rates, crop yields, and agent performance.\n\n");

    printf("8.HOW DOES AI BOT WORK?\n\n");
    printf("\t1.The built-in chatbot answers common agricultural FAQs, such as:\n");
    printf("\t\t1.1:Crop nutrition needs.\n");
    printf("\t\t1.2:Pest management strategies.\n");
    printf("\t\t1.3:Government scheme guidelines.\n");
    printf("\t2.Farmers can type questions directly at the console and receive instant, text‑based guidance.\n\n");

    printf("9.WHAT THIRD-PARTY LIBRARIES ENHANCE IN THE APPEARENCE?\n\n");
    printf("\t1.We utilize Rich (Python) for colored console output and tables.\n");
    printf("\t2.Prompt-Toolkit powers interactive menus, autocompletion, and input validation.\n\n");

    printf("10.IS MY DATA SECURE?\n\n");
    printf("\t1.All passwords are hashed using industry-standard algorithms.\n");
    printf("\t2.Role-based access controls ensure users see only permitted data.\n");
    printf("\t3.Regular backups and audit logs are maintained for accountability.\n\n");

    printf("11.HOW CAN I GET SUPPORT OR REPORT A BUG?\n\n");
    printf("\t1.Contact the system administrator via email: support@krishi-darshan.org\n");
    printf("\t2.Use the Feedback option in the main menu to log issues directly into our ticketing system.n\n");

    while (1)
    {
        int back_exit;
        printf("\t--------------------------------\n");
        printf("\t1. Go Back \n");
        printf("\t2. Exit \n");
        printf("\t--------------------------------\n\n");
        printf("\t-> Choose an option: ");
        scanf("%d", &back_exit);
        getchar();

        switch(back_exit)
        {
        case 1:
            clear_screen();
            loginMenu();
            break;
        case 2:
            exit(1);
            break;
        default:
            printf("\n\tError! Please enter a valid input!\n\n");
            continue;
        }
        break;
    }
}
