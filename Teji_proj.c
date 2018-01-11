#include<stdio.h>
#include <stdlib.h>
#define sleep int i=0; for(i=0;i<110000000;i++)

struct item
{   char name[56];
    int cost;
    int stock_count;
    int sold;
}items[10];

int curr_size=0;


void setup()
{
    int temp=0,i=0;
	FILE *fp =fopen("data.txt","r");

    while( (!feof(fp)) )
    {
        fscanf(fp,"%s %d %d %d", &items[i].name, &items[i].cost, &items[i].stock_count, &items[i].sold);
        i++;
    }

    curr_size=i;
    fclose(fp);
    return;

}

void save_prog()
{
    FILE *fp=fopen("data.txt","w");
    int i=0;
    for(i=0;i<curr_size-1;i++)
    fprintf (fp, "%s %d %d %d\n",items[i].name,items[i].cost,items[i].stock_count,items[i].sold);
    fprintf (fp, "%s %d %d %d",items[i].name,items[i].cost,items[i].stock_count,items[i].sold);
    fclose(fp);

    return;

}

void print_all()
{

    int i=0;
    for( i=0;i<10;i++)
    {
        printf("%s %d \n",items[i].name,items[i].cost);
    }
}

void clrscr()
{
    system("@cls||clear");
}


void dsp_inv()
{


    if(curr_size==0)
    {
        printf("Nothing in Inventory yet.\n");
        return;
    }

    else
    {

        printf("Item Number\t Item Name\t Number\t Unit Cost\t Value\n");
        int i=0;
        for(i=0;i<curr_size;i++){
            printf("\t%d \t %s\t\t %d\t %d\t \t  %d\n",i+1,items[i].name,items[i].stock_count,items[i].cost, (items[i].cost*items[i].stock_count) );
        }
    }
}


void dsp_trans()
{

        double total_profit=0.0;
        printf("Item Number\t Item Name\t Stock\t Sold\t Item Profit\n");
        int i=0;
        for(i=0;i<curr_size;i++)
        {
            printf("\t%d \t %s\t\t %d\t %d\t   %f\n",i+1,items[i].name, items[i].stock_count, items[i].sold, ((0.5*items[i].cost)*items[i].sold) );
            total_profit+=( ((0.5*items[i].cost)*items[i].sold) );
        }
        printf("Total Profit\t\t\t\t\t   %f\n",total_profit);

}

void refill_stock()
{
	    printf("Enter the 'Item Code' of the item to be restocked\n");
	    int i_code=-1;
	    scanf("%d",&i_code);
	    i_code--;

	    if(i_code>=curr_size || i_code<0)
	        printf("Please enter a valid Item Code, or -1 to exit and go back.\n");

	    else
	    {
	        int new_stock=0;
	        printf("Enter the new Stock count.\n");
	        scanf("%d",&new_stock);
	        items[i_code].stock_count=new_stock;
	        printf("The stock is updated.\n");
        printf("Item Number\t Item Name \t Item Cost \t In-Stock \t Sold\n");
        printf("%d\t\t %s\t\t %d\t\t %d\t\t %d\n",i_code+1,items[i_code].name,items[i_code].cost,items[i_code].stock_count,items[i_code].sold);
        return;
    }

    while( scanf("%d",&i_code) && i_code!=-1      )
    {
        i_code--;
        if(i_code>=curr_size || i_code<0)
        printf("Please enter a valid Item Code, or -1 to exit and go back.\n");
        else
        {
            int new_stock=0;
            printf("Enter the new Stock count.\n");
            scanf("%d",&new_stock);
            items[i_code].stock_count=new_stock;
            printf("The stock is updated.\n");
            printf("Item Number\t Item Name \t Item Cost \t In-Stock \t Sold\n");
            printf("%d\t\t %s\t\t %d\t\t %d\t\t %d\n",i_code+1,items[i_code].name,items[i_code].cost,items[i_code].stock_count,items[i_code].sold);
            return;
        }

    }

    return;

}

void sale()
{
    printf("Enter Item number of the item sold.\n");
    int i_code=0;

    scanf("%d",&i_code);
    i_code--;

    if(i_code>=curr_size || i_code<0)
        printf("Please enter a valid Item Code, or -1 to exit and go back.\n");

    else
    {
        int new_sold=0;
        printf("Enter the number of units sold.\n");
        scanf("%d",&new_sold);
        if( new_sold > items[i_code].stock_count )
        {
            printf("Not Enough Stock.\nGoing back to main Menu\n");
            int i=0;
            for(i=0;i<5;i++)
            {
                printf(".");
                sleep;
            }
            printf("\n");
            return;
        }
        else
        {

            items[i_code].sold+=new_sold;
            items[i_code].stock_count-=new_sold;
            printf("The Updated stock of Item Number %d after sale.\n",i_code+1);
            printf("Item Number\t Item Name \t Item Cost \t In-Stock \t Sold\n");
            printf("%d\t\t %s\t\t %d\t\t %d\t\t %d\n",i_code+1,items[i_code].name,items[i_code].cost,items[i_code].stock_count,items[i_code].sold);
            return;
        }

    }


    while( scanf("%d",&i_code) && i_code!=-1  )
        {
            i_code--;
            if(i_code>=curr_size || i_code<0)
            {
                printf("Please enter a valid Item Code, or -1 to exit and go back.\n");
            }

            else
            {
                int new_sold=0;
                printf("Enter the number of units sold.\n");
                scanf("%d",&new_sold);
                if(new_sold > items[i_code].stock_count )
                {
                    printf("Not Enough Stock.\nGoing back to main Menu");
                    int i=0;
                    for(i=0;i<5;i++)
                    {
                        printf(".");
                        sleep;
                    }
                    printf("\n");
                    return;
                    }
                else
                {
                    items[i_code].sold+=new_sold;
                    items[i_code].stock_count-=new_sold;
                    printf("The Updated stock of Item Number %d after sale.\n",i_code+1);
                    printf("Item Number\t Item Name \t Item Cost \t In-Stock \t Sold\n");
                    printf("%d\t\t %s\t\t %d\t\t %d\t\t %d\n",i_code+1,items[i_code].name,items[i_code].cost,items[i_code].stock_count,items[i_code].sold);
                    return;
                }
            }
        }

        return;
}

void order_stock()
{
        if(curr_size==10)
        {
            printf("There are 10 items in the inventory. You cannot add more.");
            return;
        }

        printf("Enter the name of the item.\n");
        scanf("%s",&items[curr_size].name);

        printf("Enter the cost of the item.\n");
        scanf("%d",&items[curr_size].cost);

        printf("Enter the count of the item.\n");
        scanf("%d",&items[curr_size].stock_count);

        items[curr_size].sold=0;
        curr_size++;

}

void delete_items()
{
        if(curr_size==0)
        {
            printf("There are no items in the inventory. You cannot delete any items.\n");
            return;
        }

        int i_code=0;

        printf("Please enter the code of the item to delete.\n");
        int temp_count=0,actual_code=0;

        while( scanf("%d",&i_code)  )
        {
            actual_code=i_code;
            i_code--;
            if( actual_code==-1 && temp_count==0 )
            {
                printf("Please enter a valid Item Code, or -1 to exit and go back.upper\n");
                temp_count++;
     			continue;
            }
            else if(actual_code==-1 && temp_count!=0)
            return;

            else if(i_code>=curr_size || i_code<0)
            {
                printf("Please enter a valid Item Code, or -1 to exit and go back.lower\n");
     			continue;
            }
            else
            {
                FILE *fp=fopen("data.txt","w");
                int i=0;
                int new_curr_size=0;
                for(i=0;i<curr_size-1;i++)
                {
                    if(i_code!=i)
                    {
                        fprintf (fp, "%s %d %d %d\n",items[i].name,items[i].cost,items[i].stock_count,items[i].sold);
                        new_curr_size++;
                    }
                }

                if(i!=i_code)
                fprintf (fp, "%s %d %d %d",items[i].name,items[i].cost,items[i].stock_count,items[i].sold);

                curr_size=new_curr_size;
                fclose(fp);
                setup();
                return;

            }
        }
/*
            else
            {
                if(new_sold > items[i_code].stock_count )
                {
                    printf("Not Enough Stock.\nGoing back to main Menu");
                    int i=0;
                    for(i=0;i<5;i++)
                    {
                        printf(".");
                        sleep;
                    }
                    printf("\n");
                    return;
                    }
                else
                {
                    items[i_code].sold+=new_sold;
                    items[i_code].stock_count-=new_sold;
                    printf("The Updated stock of Item Number %d after sale.\n",i_code+1);
                    printf("Item Number\t Item Name \t Item Cost \t In-Stock \t Sold\n");
                    printf("%d\t\t %s\t\t %d\t\t %d\t\t %d\n",i_code+1,items[i_code].name,items[i_code].cost,items[i_code].stock_count,items[i_code].sold);
                    return;
                }
            }
        }

        return;
        else
        {
        	printf("Enter the name of the item.\n");
	        scanf("%s",&items[curr_size].name);


        }



        items[curr_size].sold=0;
        curr_size++;
*/


}

int main()
{

    int choice;
    setup();

    while(1)
    {
            printf("1. Display items in inventory\n");
            printf("2. Display Transactions\n");
            printf("3. Refill Stock\n");
            printf("4. Order New Items\n");
            printf("5. Sale\n");
            printf("6. Delete Items\n");
            printf("7. EXIT\n");

            scanf("%d",&choice);

            switch(choice)
            {

            case 8:
            print_all();
            clrscr();
            break;

            case 1:
                dsp_inv();
                system("pause");
                clrscr();
                break;

            case 2:
                dsp_trans();
                system("pause");
                clrscr();
                break;

            case 3:
                refill_stock();
                system("pause");
                clrscr();
                break;

            case 4:
                 order_stock();
                 system("pause");
                 clrscr();
                 break;

            case 5:
                sale();
                system("pause");
                clrscr();
                break;

            case 6:
            	delete_items();
				system("pause");
                clrscr();
                break;

            case 7:
                printf("Exiting");
                int i=0;
                for(i=0;i<5;i++)
                {
                    printf(".");
                    sleep;
                }
                save_prog();
                exit(0);


            default:
                printf("Please enter a valid input\n");
                system("pause");
                clrscr();
                continue;


            }

    }


    return 0;
}
