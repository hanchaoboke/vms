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
* Read product information ：查看商品信息
* Insert coin ：投入硬币
* Press product button ：选择商品购买
* Press return button ：进行退币
* Open service menu (code required) ：打开管理员页面（密码验证）
* Quit ：退出系统

用户功能结构图

<img src="http://yuml.me/diagram/nofunky/class/[customer]->[Quit],[customer]->[Open service menu need code required],[customer]->[Press return button],[customer]->[Press product button],[customer]->[Insert coin],[customer]->[Read product information]" >

管理员模块主要功能  
* Inspect machine status ：查看机器状态
* Withdraw all money ：拿出所有硬币
* Refill product ：补充商品库存
* Change product ：增加新的商品取代原有商品
* Go back ：返回用户菜单

管理员功能结构图

<img src="http://yuml.me/diagram/nofunky/class/[administrator]->[Go back],[administrator]->[Change product],[administrator]->[Refill product],[administrator]->[Withdraw all money],[administrator]->[Inspect machine status]" >

## 3 系统的详细设计与实现

### 3.1 系统流程设计与实现

系统流程图

<img src="http://yuml.me/diagram/nofunky/class/[Begin]->[switch choice],[switch choice]->[0. Quit],[switch choice]->[9. Open service menu (code required)],[switch choice]->[4. Press return button],[switch choice]->[3. Press product button],[switch choice]->[2. Insert coin],[switch choice]->[1. Read product information],[0. Quit]->[exit(0)],[9. Open service menu (code required)]->[true is admin],[4. Press return button]->[return all coin],[3. Press product button]->[buy product],[2. Insert coin]->[choice coin],[1. Read product information]->[show all product information],[true is admin]->[0. Go back],[true is admin]->[4. Change product],[true is admin]->[3. Refill product],[true is admin]->[2. Withdraw all money],[true is admin]->[1. Inspect machine status],[0. Go back]->[show which choice],[4. Change product]->[change product information],[3. Refill product]->[number is MAX],[2. Withdraw all money]->[get all coin],[1. Inspect machine status]->[show coin and product information]" >


### product 商品结构体

属性名 | 描述
----|----
name | 商品名
price | 商品价格
number | 商品库存

PRODUCTMAX 商品库存最大值 10

#### 商品初始化,分别命名为A，B，C，D，E

商品名称 | 描述
----|----
A | Juice ($10) (5 left)
B | Cola($6)(1left)
C | Tea ($5) (2 left)
D | Water ($8) (1 left)
E | Coffee ($7) (9 left)

### alterProduct 商品添加函数

    void alterProduct(int productCode, char productName[], int productPrice);

参数名 | 描述
----|----
productCode | 商品编号，1代表A，2代表B···
productName[] | 商品名称，最长20字符
productPrice | 商品价格，只接受整数

管理员可以把某一个商品换成另一个商品，库存自动变为最大值 10

### moveProductNumber 商品库存修改函数

    void moveProductNumber(int productCode, int ProductNumber);

参数名 | 描述
----|----
productCode | 商品编号，1代表A，2代表B···
productNumber | 商品库存

用户购买商品，商品库存 -1 ，管理员上货，库存变成最大值 10 
