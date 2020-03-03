进度 95%

# 自动贩卖机项目设计

## 1 需求分析

### 1.1 项目描述 

自动贩卖机使用 C 语言编写，顾客可以查看商品信息，投入硬币，按下按钮购买商品，按下按钮退回投入的硬币，退出售货机；管理员通过密码验证后，可以查看机器状态，提取机器所有硬币，补充库存，更新商品

### 1.2 用户用例

customer 顾客用例

<img src="http://yuml.me/diagram/plain/usecase/[Customer]-(1. Read product information),[Customer]-(2. Insert coin),[Customer]-(3. Press product button),[Customer]-(4. Press return button),[Customer]-(9. Open service menu),(9. Open service menu)>(code required),[Customer]-(0. Quit)" >

administrator 管理员用例

<img src="http://yuml.me/diagram/plain/usecase/[Administrator]-(1. Inspect machine status),[Administrator]-(2. Withdraw all money),[Administrator]-(3. Refill product),[Administrator]-(4. Change product),[Administrator]-(0. Go back)" >

## 2 系统总体设计

### 2.1 系统的功能模块设计

本系统的功能模块由用户和管理员两部分组成  

用户模块主要功能  
用户进入系统可以使用以下功能：  
* Read product information ：查看商品信息
* Insert coin ：投入硬币
* Press product button ：选择商品购买
* Press return button ：进行退币
* Open service menu (code required) ：打开管理员页面（密码验证）
* Quit ：退出系统

用户功能结构图

<img src="http://yuml.me/diagram/nofunky/class/[customer]->[Quit],[customer]->[Open service menu need code required],[customer]->[Press return button],[customer]->[Press product button],[customer]->[Insert coin],[customer]->[Read product information]" >

管理员模块主要功能   
管理员通过密码验证后可以使用以下功能：   
* Inspect machine status ：查看机器状态
* Withdraw all money ：拿出所有硬币
* Refill product ：补充商品库存
* Change product ：增加新的商品取代原有商品
* Go back ：返回用户菜单

管理员功能结构图

<img src="http://yuml.me/diagram/nofunky/class/[administrator]->[Go back],[administrator]->[Change product],[administrator]->[Refill product],[administrator]->[Withdraw all money],[administrator]->[Inspect machine status]" >

## 3 系统的详细设计与实现

### 3.1 系统流程设计与实现

编程过程一般按照流程逐步编写，程序的每一个功能都是独立的模块，本体统功能流程图如下

<img src="http://yuml.me/diagram/nofunky/class/[Begin]->[switch choice],[switch choice]->[0. Quit],[switch choice]->[9. Open service menu (code required)],[switch choice]->[4. Press return button],[switch choice]->[3. Press product button],[switch choice]->[2. Insert coin],[switch choice]->[1. Read product information],[0. Quit]->[exit(0)],[9. Open service menu (code required)]->[true is admin],[4. Press return button]->[return all coin],[3. Press product button]->[buy product],[2. Insert coin]->[choice coin],[1. Read product information]->[show all product information],[true is admin]->[0. Go back],[true is admin]->[4. Change product],[true is admin]->[3. Refill product],[true is admin]->[2. Withdraw all money],[true is admin]->[1. Inspect machine status],[0. Go back]->[show which choice],[4. Change product]->[change product information],[3. Refill product]->[number is MAX],[2. Withdraw all money]->[get all coin],[1. Inspect machine status]->[show coin and product information]" >

### 3.2 数据库设计？

把结构体比作数据库表，结构体属性比作数据库表中的字段，依照本系统需求，合理的设计可以方便的进行数据修改，包括商品信息，硬币相关信息，管理员信息，其需求包括

1. 商品信息包括商品名、商品单价、商品库存信息
2. 硬币信息包括硬币面值、硬币营收金额记录、暂存硬币金额记录
3. 管理员信息包括管理员密码

#### 3.2.1 结构设计

依照前面关于数据的需求，可以设计商品信息实体，硬币信息实体，管理员信息实体

1. 商品信息实体

<img src="http://yuml.me/diagram/nofunky/activity/[Product]->(productName),[Product]->(productPrice),[Product]->(productNumber)" >


#### Product 商品结构体

属性名 | 描述
----|----
productName | 商品名
productPrice | 商品价格
productNumber | 商品库存

define PRODUCTNUMBERMAX 商品库存最大值 10

#### 商品结构体初始化,分别命名为A，B，C，D，E

商品名称 | 描述
----|----
A | Juice ($10) (5 left)
B | Cola($6)(1left)
C | Tea ($5) (2 left)
D | Water ($8) (1 left)
E | Coffee ($7) (9 left)

2. 硬币信息实体

<img src="http://yuml.me/diagram/nofunky/activity/[Coin]->(coinValueOne),[Coin]->(coinValueTwo),[Coin]->(coinValueFive),[Coin]->(coinValueTen),[Coin]->(coinProfit),[Coin]->(conDeposit)" >

#### Coin 硬币信息结构体

属性名 | 描述
----|----
coinValueOne | 硬币面值1元
coinValueTwo | 硬币面值2元
coinValueFive | 硬币面值5元
coinValueTen | 硬币面值10元
coinProfit | 硬币营收金额
conDeposit | 暂存硬币金额

define VALUEONE 1  
define VALUETWO 2  
define VALUEFIVE 5  
define VALUETEN 10  

#### 硬币信息结构体初始化

Coin coin;

3. 管理员信息实体

<img src="http://yuml.me/diagram/nofunky/activity/[administrator]->(adminLoginPassword)" >

#### Administrator 管理员信息结构体

属性名 | 描述
----|----
adminLoginPassword | 管理员密码

define ADMINPASSWORD 1110  管理员默认密码

#### 管理员信息结构体初始化

Administrator admin;

### 3.3 界面设计

#### 3.3.1 顾客使用主界面

顾客进入系统，就会显示售货机页面和操作选择页面。售货机页面显示标题，商品代号，价格，商品状态，投币口。操作选择页面有6种选择。

顾客使用主界面流程图，流程如下

<img src="http://yuml.me/diagram/nofunky/activity/(start)->(show mvs and choice)->(insert choice)-><a>-1>(Read product information)->(end),<a>-2>(Insert coin)->(end),<a>[which choice]-3>(Press product button)->(end),<a>-4>(Press return button)->(end),<a>-9>(Open service menu)->(end),<a>-0>(Quit)->(end),<a>-other>(show mvs and choice)" >

顾客进入系统看到贩卖机页面和选择菜单，键入选项后，根据键入的值选择操作，如果键入非法选项，则重新查看贩卖机页面和选择菜单

运行界面

关键代码

```
/*
完整的显示贩卖机页面
可以根据库存显示商品状态
无库存显示 X
投入硬币金额等于物品单价显示 O
*/
void customerPage();
void choicePage();
/*
显示系统提前设定好的选项，接收选项对应的数字
1 void Readproductinformation();  查看商品信息
2 void InsertCoin();  投入硬币
3 void PressProductButton();  购买商品
4 void PressReturnButton();  退币
9 void OpenServiceMenu();  进入管理员选项（需要密码）
0 void Quit();  退出系统
*/
void choiceResultPage(int insertChoice);

customerPage();
    int insertChoice = -1;
    while (insertChoice != 1 ||insertChoice != 2 ||insertChoice != 3 ||insertChoice != 4 ||insertChoice != 9 ||insertChoice != 0)
    {
        choicePage();
        printf("Your choice:");  sacnf("%d",&insertChoice);
        if (insertChoice != 1 ||insertChoice != 2 ||insertChoice != 3 ||insertChoice != 4 ||insertChoice != 9 ||insertChoice != 0)
        {
            puts("Invalid choice!");
        }
        else
        {
            choiceResultPage(insertChoice);
        } 
    }

```
#### 3.3.2 查看商品信息界面

用户选择1后，系统跳转至查看商品信息界面，显示商品对应贩卖机序号，商品名称，商品价格，商品库存

查看商品信息界面流程图，流程如下

<img src="http://yuml.me/diagram/nofunky/activity/(start)->(read product information)->(end)" >

顾客可以查看商品信息

运行界面

关键代码

```
/*
商品信息展示，包括商品名称和商品价格
*/
void Readproductinformation(){
    printf("A. %s ($ %d)",A.productName,A.productPrice);
    printf("B. %s ($ %d)",B.productName,B.productPrice);
    printf("C. %s ($ %d)",C.productName,C.productPrice);
    printf("D. %s ($ %d)",D.productName,D.productPrice);
    printf("E. %s ($ %d)",E.productName,E.productPrice);
}
```

#### 3.3.3 投入硬币界面

用户投入给定面值的硬币，投币口自动叠加投入硬币的金额，当投入的硬币金额大于等于商品单价时，亮灯

投入硬币界面流程图，流程如下

<img src="http://yuml.me/diagram/nofunky/activity/(start)->(insert coin)->(change price of product)->(end)" >

用户投入硬币，贩卖机投币口金额叠加，看到贩卖机商品是否可以购买

运行界面

关键代码

```
/*
用户只能投入给定面值的硬币，贩卖机的商品状态，投币口金额会发生变化
*/
void InsertCoin()
{
    int InsertCoin = -1;
    while (InsertCoin != 0)
    {
        // 贩卖机页面
        customerPage();
        // 投入硬币页面
        puts("(2) Which coin would you like to insert?");
        puts("1. $1");
        puts("2. $2");
        puts("3. $5");
        puts("4. $10");
        puts("0. Go back\n");
        printf("Your choice:");
        scanf("%d", &InsertCoin);
        switch (InsertCoin)
        {
        case 1:
            coin.conDeposit += coin.coinValueOne;
            break;
        case 2:
            coin.conDeposit += coin.coinValueTwo;
            break;
        case 3:
            coin.conDeposit += coin.coinValueFive;
            break;
        case 4:
            coin.conDeposit += coin.coinValueTen;
            break;
        case 0:
            puts("Going back!");
            break;
        default:
            puts("insert wrong coin");
            break;
        }
    }
}
```
#### 3.3.4 购买商品界面

用户选择想要购买商品的序号，系统自动扣除投币口内的硬币，商品从出货口弹出

购买商品界面流程图，流程如下

<img src="http://yuml.me/diagram/nofunky/activity/(start)->(show product)-><a>[whilch product]->(buy product)->(end)" >

运行界面

关键代码

```
/*
商品代码,A,B,C,D,E
*/
char producCode;
/*
购买商品的业务逻辑
*/
void outProduct(Product product,char code,char* producCode){
    product.productNumber -= 1;
    *producCode = code;
    coin.coinProfit += product.productPrice;
}
/*
用户输入商品代号，购买商品
*/
void PressProductButton(){
    int productButton;
    puts("(3) Which product button would you like to press?");
    puts("1. A");
    puts("2. B");
    puts("3. C");
    puts("4. D");
    puts("5. E");
    puts("0. Go back\n");
    printf("Your choice:"); scanf("%d",&productButton);
    switch (productButton)
    {
    case 1:
        puts("You have pressed button A.");
        outProduct(A,'A',&producCode);
        break;
    case 2:
        puts("You have pressed button B.");
        outProduct(B,'B',&producCode);
        break;
    case 3:
        puts("You have pressed button C.");
        outProduct(C,'C',&producCode);
        break;
    case 4:
        puts("You have pressed button D.");
        outProduct(D,'D',&producCode);
        break;
    case 5:
        puts("You have pressed button E.");
        outProduct(E,'E',&producCode);
        break;
    case 0:
        puts("Going back!");
        break;
    default:
        puts("wrong choice!");
        break;
    }
    
}
```

#### 3.3.5 退币界面

用户选择退币后，投币口清零

退币界面流程图，流程如下

<img src="http://yuml.me/diagram/nofunky/activity/(start)->(return button)->(show mvs and choice)->(end)" >

运行界面

关键代码

```
/*
用户退币
*/
void PressReturnButton(){
    coin.conDeposit = 0;
}
```

#### 3.3.6 进入管理员用户界面

用户选择管理员后，进行密码验证，验证错误返回主页面，验证正确进入管理员选择菜单

管理员用户界面流程图，流程如下

<img src="http://yuml.me/diagram/nofunky/activity/(start)->(verify password)->(show choice)-><a>-1>(InspectMachineStatus)->(end),<a>[which choice]-2>(WithdrawAllMoney)->(end),<a>-3>(RefillProduct)->(end),<a>-4>(ChangeProduct)->(end),<a>-0>(GoBack)->(end),<a>-other>(show choice)" >

运行界面


关键代码

```
void adminChoicePage()
{
    puts("(9) What would you like to do?");
    puts("1. Inspect machine status");
    puts("2. Withdraw all money");
    puts("3. Refill product");
    puts("4. Change product");
    puts("0. Go back\n");
}
/*
显示系统提前设定好的选项，接收选项对应的数字
1 void InspectMachineStatus();  查看商品信息
2 void WithdrawAllMoney();  投入硬币
3 void RefillProduct();  购买商品
4 void ChangeProduct();  退币
0 void GoBack();  进入管理员选项（需要密码）
*/
void adminChoiceResultPage(int adminChoiceCode);

void administratorPage()
{
    int adminPassword;
    puts("(9) Opening service menu. Access code is required.");
    printf("Enter access code:");
    scanf("%d", &adminPassword);
    if (adminPassword == ADMINPASSWORD)
    {
        int adminChoiceCode = -1;
        puts("Correct code!\n");
        while (adminChoiceCode != 1 || adminChoiceCode != 2 || adminChoiceCode != 3 || adminChoiceCode != 4 || adminChoiceCode != 0)
        {
            adminChoicePage();
            printf("Your choice:");
            scanf("%d", &adminChoiceCode);
            adminChoiceResultPage(adminChoiceCode);
        }
    }
    else
    {
        puts("password is wrong");
    }
}
```

##### 3.3.6.1 查看机器状态

用户查看机器的各种状态，盈利金额，投币口硬币金额，商品代码，名称，单价，库存

运行界面

关键代码

```
/*
查看机器状态
*/
void InspectMachineStatus(){
    puts("(9-1) Machine status");
    printf("Amount of revenue: $ %d",coin.coinProfit);
    printf("Amount of inserted coins: $ %d",coin.conDeposit);
    printf("A. %s ($ %d) ( %d left)",A.productName,A.productPrice,A.productNumber);
    printf("B. %s ($ %d) ( %d left)",B.productName,B.productPrice,B.productNumber);
    printf("C. %s ($ %d) ( %d left)",C.productName,C.productPrice,C.productNumber);
    printf("D. %s ($ %d) ( %d left)",D.productName,D.productPrice,D.productNumber);
    printf("E. %s ($ %d) ( %d left)",E.productName,E.productPrice,E.productNumber);
    puts("\n");
}
```

##### 3.3.6.2 取出盈利的硬币

用户取出盈利硬币和投币口里的硬币

运行界面

关键代码

```
/*
取出盈利的硬币
*/
void WithdrawAllMoney(){
    coin.coinProfit = 0;
    coin.conDeposit = 0;
}
```

##### 3.3.6.3 补充商品库存

用户需要选择要添加库存的商品，添加库存至满

运行界面

关键代码

```
/*
moveProductNumber 商品库存修改函数
*/
void moveProductNumber(int productCode){
    switch (productCode)
    {
    case 1:
        A.productNumber = PRODUCTNUMBERMAX;
        puts("You have refilled product A to full.\n");
        break;
    case 2:
        B.productNumber = PRODUCTNUMBERMAX;
        puts("You have refilled product B to full.\n");
        break;
    case 3:
        C.productNumber = PRODUCTNUMBERMAX;
        puts("You have refilled product C to full.\n");
        break;
    case 4:
        D.productNumber = PRODUCTNUMBERMAX;
        puts("You have refilled product D to full.\n");
        break;
    case 5:
        E.productNumber = PRODUCTNUMBERMAX;
        puts("You have refilled product E to full.\n");
        break;
    }
}
/*
补充商品库存
*/
void RefillProduct(){
    int RefillProductCode;
    puts("(9-3) Which product would you like to refill?");
    puts("1. A\n2. B\n3. C\n4. D\n5. E\n0. Go back\n");
    printf("Your choice:"); scanf("%d",&RefillProductCode);
    moveProductNumber(RefillProductCode);
}
```

##### 3.3.6.4 更新商品

用户输入要修改的商品代码进行修改内容

运行界面

关键代码

```
/*
商品添加函数
*/
void alterProduct(Product product, char productName[20], int productPrice){
    strcpy(product.productName,productName);
    product.productPrice = productPrice;
    product.productNumber = PRODUCTNUMBERMAX;
}
/*
更新商品
*/
void ChangeProduct(){
    int ChangProductCode;
    char ChangProductName[20];
    int ChangProductPrice;
    puts("(4-4) Which product would you like to change?");
    puts("1. A\n2. B\n3. C\n4. D\n5. E\n0. Go back\n");
    printf("Your choice:"); scanf("%d",&ChangProductCode);
    puts("You are changing product\n");
    printf("Enter new product name:");  scanf("%s",ChangProductName);
    printf("Enter new product price:"); scanf("%d",&ChangProductPrice);
    switch (ChangProductCode)
    {
    case 1:
        alterProduct(A,ChangProductName,ChangProductPrice);
        break;
    case 2:
        alterProduct(B,ChangProductName,ChangProductPrice);
        break;
    case 3:
        alterProduct(C,ChangProductName,ChangProductPrice);
        break;
    case 4:
        alterProduct(D,ChangProductName,ChangProductPrice);
        break;
    case 5:
        alterProduct(E,ChangProductName,ChangProductPrice);
        break;
    }
    puts("The new product has been filled to full.");


}
```

##### 3.3.6.5 返回顾客主页

用户选择后，回退到顾客主页

运行界面

关键代码

```
/*
返回顾客主页
*/
void GoBack(){
    
}
```

#### 3.3.7 退出系统界面

用户选择此选项后，系统退出

退出系统界面流程图，流程如下

<img src="http://yuml.me/diagram/nofunky/activity/(start)->(exit)->(end)" >

运行界面

关键代码

```
/*
用户退出系统
*/
void Quit(){
    exit(0);
}
```


