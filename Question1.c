//Function that returns fibonacci sequence based on the following arithmetic operations (+, -, *, /) and conditions. Implemented using Dynamic Programming.


#include <stdio.h>
#include <stdlib.h>

typedef enum TypeTag
{
    ADD,
    SUB,
    MUL,
    DIV,
    CONST
} TypeTag;

typedef struct Node
{
    TypeTag type;
    union {
        int value;
        struct {
            struct Node* left;
            struct Node* right;
        } operands;
    } data;
} Node;

Node* makeFunc(TypeTag tag)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->type = tag;
    return node;
}

int calc(Node* node)
{
    if (node == NULL)
        return 0;

    if (node->type == CONST)
        return node->data.value;

    int left = calc(node->data.operands.left);
    int right = calc(node->data.operands.right);

    switch (node->type)
    {
        case ADD:
            return left + right;
        case SUB:
            return left - right;
        case MUL:
            return left * right;
        case DIV:
            return left / right;
        default:
            return 0;
    }
}

int fibonacci(int n)
{
    if (n <= 1)
        return n;

    int a = 0;
    int b = 1;
    int fib = 0;

    for (int i = 2; i <= n; i++)
    {
        fib = a + b;
        a = b;
        b = fib;
    }

    return fib;
}

int main()
{
    Node* add = makeFunc(ADD);
    add->data.operands.left = makeFunc(CONST);
    add->data.operands.left->data.value = 10;
    add->data.operands.right = makeFunc(CONST);
    add->data.operands.right->data.value = 6;

    Node* mul = makeFunc(MUL);
    mul->data.operands.left = makeFunc(CONST);
    mul->data.operands.left->data.value = 5;
    mul->data.operands.right = makeFunc(CONST);
    mul->data.operands.right->data.value = 4;

    Node* sub = makeFunc(SUB);
    sub->data.operands.left = mul;
    sub->data.operands.right = add;

    Node* fibo = makeFunc(SUB);
    fibo->data.operands.left = sub;
    fibo->data.operands.right = NULL;


    int addResult = calc(add);
    int mulResult = calc(mul);
    int subResult = calc(sub);
    int fiboResult = calc(fibo);

    printf("add : %d\n", addResult);
    printf("mul : %d\n", mulResult);
    printf("sub : %d\n", subResult);
    printf("fibo : %d\n", fiboResult);


    free(add);
    free(mul);
    free(sub);
    free(fibo);

    return 0;
}