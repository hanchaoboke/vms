## 自动贩卖机项目设计

### product 商品结构体

属性名 | 描述
----|----
name | 商品名
price | 商品价格
number | 商品库存

#### 商品初始化,分别命名为A，B，C，D，E

商品名称 | 描述
----|----
A | Juice ($10) (5 left)
B | Cola($6)(1left)
C | Tea ($5) (2 left)
D | Water ($8) (1 left)
E | Coffee ($7) (9 left)

### alterProduct 商品添加函数

void alterProduct(int productCode, char productName[], int productPrice, int productNumber);

参数名 | 描述
----|----
productCode | 商品编号，1代表A，2代表B···
productName[] | 商品名称，最长20字符
productPrice | 商品价格，只接受整数
productNumber | 商品库存
