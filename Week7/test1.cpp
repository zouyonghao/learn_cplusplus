template <class T1, class T2>
class A {
    T2 b;
    T1 fun(double a) {
        b = (T2) a;
        return (T1) b;
    }
};