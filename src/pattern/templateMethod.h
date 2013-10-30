/* 
 * Template method
 * Author: GOro
 *
 * Created on 2013. október 4., 1:06
 */

#ifndef TEMPLATEMETHOD_H
#define	TEMPLATEMETHOD_H

class AbstractAlgorithm {
protected:
    virtual void doOperation1() = 0;
    virtual void doOperation2() = 0;
    virtual void doOperation3() = 0;
public:
    void operation() {
        doOperation1();
        doOperation2();
        doOperation3();
    }
};

class ConcreteAlgorithm : public AbstractAlgorithm {
private:
    doOperation1() {
        // Implements op1;
    }
};

#endif	/* TEMPLATEMETHOD_H */

