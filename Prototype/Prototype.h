#ifndef _PROTOTYPE_H_
#define _PROTOTYPE_H_

/*
*   原型模式
*   使用原型实例来指定待创建对象的类型，并且通过复制原型来完成对象的创建
*/

//工作模型类WorkModel
class WorkModel
{
public:
    WorkModel(){}
    void setModelName(char *iModelName)
    {
        this->modelName = iModelName;
    }


    char *modelName;
};

//抽象原型类PrototypeWork
class PrototypeWork
{
public:
    PrototypeWork(){}
    virtual PrototypeWork *clone() = 0;
};

//具体原型类ConcreteWork
class ConcreteWork : public PrototypeWork
{
public:
    ConcreteWork(){}
    ConcreteWork(char *iName, int iIdNum, char *iWorkModel)
    {
        this->name = iName;
        this->idNum = iIdNum;
        workModel = new WorkModel();
        workModel->setModelName(iWorkModel);
    }
    void setName(char *iName)
    {
        this->name = iName;
    }
    void setIdName(int iIdName)
    {
        this->idNum = iIdName;
    }
    void setWorkModel(WorkModel *iWorkModel)
    {
        this->workModel = iWorkModel;
    }
    void printfWorkInfo()
    {
        printf("name: %s\t\n", this->name);
        printf("idName: %d\t\n", this->idNum);
        printf("workModel: %s\t\n", this->workModel->modelName);
    }

    ConcreteWork *clone()
    {
        ConcreteWork *work = new ConcreteWork();
        work->setName(this->name);
        work->setIdName(this->idNum);
        work->setWorkModel(this->workModel);
        return work;
    }

private:
    char *name;
    int idNum;
    WorkModel *workModel;
};

#endif