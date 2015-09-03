#ifndef VARIABLES_H
#define VARIABLES_H

#include <QString>
#include <QList>

struct PRODUCT
{
    short index;
    int quantity;
    QString strName;
    QString strTime;
    QString strDate;
    float price;
};

class Variables
{
public:
    Variables();
    void setIndex(short idx) {currentProduct.index = idx;}
    void setQuantity(int data) {currentProduct.quantity = data;}
    void setName(QString strName) {currentProduct.strName = strName;}
    void setTime(QString strData) {currentProduct.strTime = strData;}
    void setDate(QString strData) {currentProduct.strDate = strData;}
    void setPrice(float data) {currentProduct.price = data;}

    short getIndex() {return currentProduct.index;}
    int getQuantity() {return currentProduct.quantity;}
    QString getName() {return currentProduct.strName;}
    QString getTime() {return currentProduct.strTime;}
    QString getDate() {return currentProduct.strDate;}
    float getPrice() {return currentProduct.price;}

    QList<QString>  m_productUsedName;
    QList<int> m_productSold;

    QList<PRODUCT> m_currentProductList;
    struct PRODUCT currentProduct;
    QString m_strMsg;
};
extern Variables *variables;
#endif // VARIABLES_H
