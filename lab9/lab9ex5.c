#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 30

typedef struct {
    int item;
    char operator;  // 0 if operand
} Fmla_Item;

typedef struct {
    int n;
    int d;
} Fract;

int prec(char op) {
    switch (op)
    {
    case '*':
    case '/':
        return 2;
        break;
    case '+':
    case '-':
        return 1;
        break;
    default:
        break;
    }
    return 0;
}

// return number of items in the array
int parse(const char ops[], int n_ops, Fmla_Item items[]) {
    char op_stack[BUF_SIZE];
    int op_count = 0;
    int item_count = 0;
    Fmla_Item first = {0, 0};
    items[item_count] = first;
    item_count++;
    for (int i = 0; i < n_ops; i++) {
        while (op_count > 0 && prec(op_stack[op_count-1]) >= prec(ops[i])) {
            Fmla_Item item = {0, op_stack[op_count-1]};
            items[item_count] = item;
            item_count++;
            op_count--;
        }
        op_stack[op_count] = ops[i];
        op_count++;
        Fmla_Item item = {i+1, 0};
        items[item_count] = item;
        item_count++;
    }
    while (op_count > 0) {
        Fmla_Item item = {0, op_stack[op_count-1]};
        items[item_count] = item;
        item_count++;
        op_count--;
    }
    return item_count;
}

Fract eval(int nums[], const Fmla_Item items[], int n_items) {
    Fract nums_stack[BUF_SIZE];
    int nums_stack_size = 0;
    for (int i = 0; i < n_items; i++)
    {
        if (items[i].operator == 0) {
            // number
            nums_stack[nums_stack_size].n = nums[items[i].item];
            nums_stack[nums_stack_size].d = 1;
            nums_stack_size++;
            continue;
        }
        // Operator
        Fract b = nums_stack[nums_stack_size-1];
        nums_stack_size--;
        Fract a = nums_stack[nums_stack_size-1];
        nums_stack_size--;
        Fract res;
        switch (items[i].operator)
        {
        case '+':
            res.n = a.n * b.d + b.n * a.d;
            res.d = a.d * b.d;
            break;
        case '-':
            res.n = a.n * b.d - b.n * a.d;
            res.d = a.d * b.d;
            break;
        case '*':
            res.n = a.n * b.n;
            res.d = a.d * b.d;
            break;
        case '/':
            res.n = a.n * b.d;
            res.d = a.d * b.n;
            break;
        }
        nums_stack[nums_stack_size] = res;
        nums_stack_size++;
    }
    return nums_stack[nums_stack_size-1];
}

void permu(int *seq, int n, int k, Fmla_Item fmla[], int fmla_len, int target, int *counter) {
    // General case
    if (n == 0) {
        Fract ans = eval(seq, fmla, fmla_len);
        if (ans.d == 0) return;
        div_t div_ans = div(ans.n, ans.d);
        if (div_ans.rem == 0 && div_ans.quot == target) {
            (*counter)++;
        }
        return;
    }
    for (int i = 0; i < 10; i++)
    {
        seq[k] = i;
        permu(seq, n-1, k+1, fmla, fmla_len, target, counter);
    }
    
}

int main(int argc, char** argv) {
    int n;
    scanf("%d", &n);
    char ops[BUF_SIZE];
    for (int i = 0; i < n; i++) {
        scanf(" %c", &ops[i]);
    }
    int c;
    scanf("%d", &c);
    Fmla_Item fmla[BUF_SIZE];
    int fmla_size = parse(ops, n, fmla);
    int count = 0;
    int seq[10];
    // int seq1[10] = {2, 1, 2, 4, 8, 1};
    // eval(seq1, fmla, fmla_size);
    permu(seq, n+1, 0, fmla, fmla_size, c, &count);
    printf("%d", count);
    return 0;
}