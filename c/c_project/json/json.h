#ifndef T_JSON_H_
#define T_JSON_H_
//先写需要什么函数  然后去写函数 最后再去写测试单元
//json 包含 6 种数据类型
//类型及函数则用小写 通常枚举值用全大写
typedef enum {T_NULL,T_FALSE,T_TURE,T_NUMBER,T_STRING,T_ARRAY,T_OBJ} t_type;

typedef struct 
{
    char *s;
    int len;//size_t 没有
    double n;//用于数字的表达
    t_type type; 
}t_value; // pt_value 事实上是一种变体类型（variant type），
//我们通过 type 来决定它现时是哪种类型，而这也决定了哪些成员是有效的


// typedef struct {
//     union {
//         struct { char* s; size_t len; }s;  /* string */
//         double n;                          /* number */
//     }u;
//     lept_type type;
// }lept_value; 然而我们知道，一个值不可能同时为数字和字符串，因此我们可使用 C 语言的 union 来节省内存：
//我们要把之前的 v->n 改成 v->u.n。而要访问字符串的数据，则要使用 v->u.s.s 和 v->u.s.len。这种写法比较麻烦

enum{//不合法的是啥类型的
    T_PARSE_OK = 0,// 无错误
    T_PARSE_EXPECT_VALUE,//一个 JSON 只含有空白
    T_PARSE_INVALID_VALUE,//不是null、false 或 true那三种字面值
    T_PARSE_ROOT_NOT_SINGULAR,//一个值之后，在空白之后还有其他字符
    T_PARSE_NUMBER_TOO_BIG,

    T_PARSE_MISS_QUOTATION_MARK,
    T_PARSE_INVALID_STRING_ESCAPE,
    T_PARSE_INVALID_STRING_CHAR

};

#define t_init(v) do { (v)->type = T_NULL; } while (0) // 初始化 用于堆栈 处理  字符串 因为难以确定他的大小所以用来堆栈 随时可以添加
void t_free(t_value* v);//释放空间
#define t_set_null(v) t_free(v)

int t_get_boolean(const t_value* v);
void t_set_boolean(t_value* v, int b);

const char* t_get_string(const t_value* v);// 获取字符串
int t_get_string_length(const t_value* v);// 获取字符串的长度
void t_set_string(t_value* v, const char* s, int len);// 设置字符串 size_t


int t_parse(t_value *v,const char* json);//解析 JSON  看看是否合法
t_type t_get_type(const t_value *v);//访问结果的函数  不合法的话看看是啥类型
double t_get_number(const t_value *v);//处理数字

#endif