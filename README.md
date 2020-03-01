进度 25%

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

### alterProduct 商品添加函数

    void alterProduct(int productCode, char productName[], int productPrice);

参数名 | 描述
----|----
productCode | 商品编号，1代表A，2代表B···
productName[] | 商品名称，最长20字符
productPrice | 商品价格，只接受整数

管理员可以把某一个商品换成另一个商品，库存自动变为最大值

### moveProductNumber 商品库存修改函数

    void moveProductNumber(int productCode, int ProductNumber);

参数名 | 描述
----|----
productCode | 商品编号，1代表A，2代表B···
productNumber | 商品库存

用户购买商品，商品库存 -1 ，管理员上货，库存变成最大值 10 
