/* 
 * Singleton
 * Use NULL macro on compilers without C++11 support.
 */

#ifndef SINGLETON_H
#define	SINGLETON_H
namespace sandbox {
namespace pattern {

class Singleton {
private:
    static Singleton* instance_;
    Singleton() : magic(42) {}
    ~Singleton(){
        delete instance_;
    }
    int magic;
public:
    static Singleton* instance() {
        if (instance_ == nullptr) {
            instance_ = new Singleton;
        }
        return instance_;
    }
    int doMagic() {
        int temp = magic;
        magic *= magic;
        return temp;
    }
};
Singleton* Singleton::instance_ = nullptr;
}
}

#endif	/* SINGLETON_H */

