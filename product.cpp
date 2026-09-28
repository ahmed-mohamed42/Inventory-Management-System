    #include <bits/stdc++.h>
    using namespace std;

    #define ll long long
    #define ull unsigned long long
    #define dd  double
    #define fs fixed << setprecision
    #define el <<'\n';
    #define cel cout << '\n';
    #define sp cout<<" ";
    #define all(v) v.begin(), v.end()
    #define rall(v) v.rbegin(), v.rend()
    #define yes cout << "YES\n";
    #define no cout << "NO\n";
    #define kill return 0;
    #define kil return
    #define  pi 3.14;


    const int MAX=100; 
    int product_ID[MAX];
    string product_Name[MAX];
    float product_Price[MAX];
    int product_Quantity[MAX];

    int count_Products = 0;
    int find_Product(int x){
        for(int i=0;i<count_Products;i++)
        {
            if(product_ID[i]==x)kil i;
        }
        kil -1;
    }
    void Sort_Products(){
        for (int i = 0; i < count_Products-1; i++)
        {
            for (int j = i+1; j < count_Products; j++)
            {
               if(product_ID[i]>product_ID[j]){
                swap(product_ID[i],product_ID[j]);
                swap(product_Name[i],product_Name[j]);
                swap(product_Price[i],product_Price[j]);
                swap(product_Quantity[i],product_Quantity[j]);
               }
            }
        }
    }

    void Add_Product()
    {
        if(count_Products==MAX){
            cout<<"Inventory is Full." el
            kil;
        }
        cel
        cout<<"===========================" el
        cout << "Add Product" << endl;
        cout<<"===========================" el

    cout << "Enter Product ID: ";
    cin >> product_ID[count_Products];

    if (find_Product(product_ID[count_Products]) != -1)
    {
        cout << "Product Already Exists.\n";
        kil;
    }
    cin.ignore();
    cout << "Enter Product Name: ";
    getline(cin,product_Name[count_Products]);
    
    cout << "Enter Product Price: ";
    cin >> product_Price[count_Products];

    cout << "Enter Product Quantity: ";
    cin >> product_Quantity[count_Products];

    count_Products++;
    Sort_Products();
    cel
    cout << "Product Added Successfully." << endl;
    cel
    //2
    };
    void Search_Product()
    {
        int id;
        bool found = false;

        cout << "Search Product" << endl;
        cout << "Enter Product ID: ";
        cin >> id;
        for (int i = 0; i < count_Products; i++)
    {
        if (product_ID[i] == id)
        {
            cout << "Product Found" << endl;
            cout << "ID: " << product_ID[i] << endl;
            cout << "Name: " << product_Name[i] << endl;
            cout << "Price: " << product_Price[i] << endl;
            cout << "Quantity: " << product_Quantity[i] << endl;

            found = true;
            break;
        }
    }
    if (found == false)
    {
        cout << "Product Not Found." << endl;
    }
    }
    //3
    void Update_product()
    {
        cout<<"===========================" el
        cout<<"     Update Product" el
        cout<<"===========================" el
        int id;
        cout << "Enter product ID to update: ";
        cin>>id;
        for (int i=0;i<count_Products;i++)
        {
            if(product_ID[i]==id)
            {
                cout << "\"product found enter new details\"" el
                cin.ignore();
                char c;
                cout<<"Change Name? (y/n): ";cin>>c;
                if(c=='y'||c=='Y'){
                    cout << "Enter New Name: ";
                    getline(cin,product_Name[i]);
                }
                cout<<"Change Price? (y/n): ";cin>>c;
                if(c=='y'||c=='Y'){
                    cout << "Enter New price: ";
                    cin>> product_Price[i];
                }
                cout<<"Change Quantity? (y/n): ";cin>>c;
                if(c=='y'||c=='Y'){
                    cout << "Enter New quantity: ";
                    cin>> product_Quantity[i];
                }
                cout << "product update successfully" el
                Sort_Products();
                return;
            }
        }
        cel
        cout << "\"product ID Not Found\"" el
        cel
    }
    //4
    void delete_product ()
    {
        cout<<"===========================" el
        cout<<"     Delete Product" el
        cout<<"===========================" el
        int id;
        cout << "Enter product ID to delete: ";
        cin>>id;
        for (int i=0;i<count_Products;i++)
        {
            if (product_ID[i]==id)
            {
                for (int j=i;j<count_Products-1;j++)
                {
                    product_ID[j]=product_ID[j+1];
                    product_Name[j]= product_Name[j+1];
                    product_Price[j]=product_Price[j+1];
                    product_Quantity[j]=product_Quantity[j+1];
                }
                count_Products--;
                Sort_Products();
                cout << "product delete successfully" el
                kil;
            }
        }
        cel
        cout << "\"product ID Not Found\"" el
        cel
    }
    //5
    void Sell_Product(){
        cout<<"===========================" el
        cout<<"     Sell Product" el
        cout<<"===========================" el

        int Quantity,ID;
        cout<<"Enter Product ID:";cin>>ID;
        cout<<"Enter Quantity:";cin>>Quantity;
        if(Quantity<=0){
            cout<<"Invalid Quantity." el
            kil;
        }
        for (int i = 0; i < count_Products; i++)
        {
          
            if(product_ID[i]==ID){
                if(product_Quantity[i]<Quantity)
                cout<<"Not Enough Stock." el
                else {
                    product_Quantity[i]-=Quantity;
                    cout<<"Product Sold Successfully." el
                }
                kil;
            }
        }
        cel
        cout<<"\"Product Not Found.\"" el
        cel
    }
    //8-Display Inventory
    void Display_Inventory(){
        cel
        if(count_Products==0){
            cout<<"\"No Products Found.\"" el cel
        kil;
    }
        cout<<"===========================" el
        cout<<"     Display Inventory" el
        cout<<"===========================" el
        cout<<"Total Products:"<<count_Products el cel 
        for (int i = 0; i < count_Products; i++)
        {
            cout<<"===========================" el
            cout<<"product ID:"<<product_ID[i] el
            cout<<"product Name:"<<product_Name[i] el
            cout<<"product Price:"<<product_Price[i] el
            cout<<"product Quantity:"<<product_Quantity[i] el
            cout<<"===========================" el cel
        }
        
        
    }
    //7-Low Stock Alert
    void Low_Stock_Alert(){
        bool flag=false;
        cel
        cout<<"===========================" el
        cout<<"    Low Stock Alert" el
        cout<<"===========================" el cel

        for (int i = 0; i < count_Products; i++)
        {
            if(product_Quantity[i]<5){
                
                cout<<"product ID:"<<product_ID[i] el
                cout<<"product Name:"<<product_Name[i] el
                cout<<"product Price:"<<product_Price[i] el
                cout<<"product Quantity:"<<product_Quantity[i] el
                cout<<"_________________________" el cel
                flag=true;
            }
        }
        if(!flag)cout<<"No Low Stock Products." el cel
    }

    int main() {
        ios::sync_with_stdio(false);
        cout.tie(nullptr);

        while (true)
        {
            int Choose;
            cout<<"===========================" el
            cout<<"    Inventory System" el
            cout<<"===========================" el
            cout<<"1. Add Product" el
            cout<<"2. Update Product" el
            cout<<"3. Delete Product" el
            cout<<"4. Sell Product" el
            cout<<"5. Search Product" el
            cout<<"6. Display Inventory" el
            cout<<"7. Low Stock Alert" el
            cout<<"8. Exit" el
            cout<<"Choose: _";
            cin>>Choose;

            if(Choose==1)Add_Product();
            else if(Choose==2)Update_product();
            else if(Choose==3)delete_product();
            else if (Choose==4)Sell_Product();
            else if(Choose==5)Search_Product();
            else if (Choose==6)Display_Inventory();
            else if(Choose==7)Low_Stock_Alert() ;
            else if(Choose==8)break;
            else 
            cout<<"This option is not implemented yet." el

        }
        kill;
    }