#include <stdio.h>

void main() {
    //值传递和引用传递
    //其实，不管是值传递还是引用传递，传递给函数的都是变量的副本，不同的是，值传递的是值的拷贝，引用传 递的是地址的拷贝，
    //一般来说，地址拷贝效率高，因为数据量小，而值拷贝决定拷贝的数据大小，数据越大，效率 越低。
    //特点
    // 1.值传递 变量直接存储值 内存通常分配在栈中。
    // 2.默认使用值传递的数据类型有 基本数据类型、结构体、共用体、枚举类型。
    // 3.引用传递 变量存储的是一个地址 这个地址对应的空间才是真正存储的值
    // 4.默认使用引用传递的数据类型有 指针和数组
    // 5.如果希望函数内的变量能修改函数外的变量，可以传入变量的地址&，函数内以指针的方式操作变量(*指针)。 从效果上看类似引用

    //变量作用域
    // 1.函数内部声明/定义的局部变量，作用域仅限于函数内部。
    // 2.函数的参数，形式参数，被当作该函数内的局部变量，如果与全局变量同名它们会优先使用局部变量(编译器 使用就近原则)
    // 3.在一个代码块，比如for/if中的局部变量，那么这个变量的的作用域就在该代码块
    // 4.在所有函数外部定义的变量叫全局变量，作用域在整个程序有效

    //局部变量和全局变量
    // 1.局部变量，系统不会对其默认初始化，必须对局部变量初始化后才能使用，否则，程序运行后可能会异常退出.
    // 2.全局变量，系统会自动对其初始化
    // 3.正确地初始化变量是一个良好的编程习惯，否则有时候程序可能会产生意想不到的结果，因为未初始化的变量 会导致一些在内存位置中已经可用的垃圾值

    //作用域注意细节
    // 1.全局变量(GlobalVariable)保存在内存的全局存储区中，占用静态的存储单元，它的作用域默认是整个程序，也就是所有的代码文件，包括源文件(.c 文件)和头文件(.h 文件)。
    // 2.局部变量(LocalVariable)保存在栈中，函数被调用时才动态地为变量分配存储单元，它的作用域仅限于函数内 部。
    // 3.C 语言规定，只能从小的作用域向大的作用域中去寻找变量，而不能反过来，使用更小的作用域中的变量
    // 4.在同一个作用域，变量名不能重复，在不同的作用域，变量名可以重复，使用时编译器采用就近原则.
    // 5.由{}包围的代码块也拥有独立的作用域
}

// 说明