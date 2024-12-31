#include <iostream>

using namespace std;

struct node {
    int value;
    node* left;
    node* right;

    node(int key) {
        value = key;
        left = nullptr;
        right = nullptr;
    }

    ~node() {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};

// Проверяет, существует ли элемент со значением value в дереве с корнем root
bool exists(node* root, int value) {
    if (root == nullptr)
        return false;
    if (root->value == value)
        return true;
    if (value < root->value)
        return exists(root->left, value);
    else
        return exists(root->right, value);
}

// Вставляет элемент со значением value в дерево с корнем root
node* insert(node* root, int value) {
    if (exists(root, value))
        return root;
    if (root == nullptr)
        return new node(value);

    if (value < root->value)
        root->left = insert(root->left, value);
    else if (value > root->value)
        root->right = insert(root->right, value);

    return root;
}

// Вычисляет глубину дерева с корнем root
int depth(node* root) {
    if (root == nullptr)
        return 0;

    int leftDepth = depth(root->left);
    int rightDepth = depth(root->right);

    return max(leftDepth, rightDepth) + 1;
}

// Выводит значения элементов дерева, используя обход в глубину
void print(node* root, int depth = 0) {
    if (root == nullptr)
        return;

    print(root->right, depth + 1);

    for (int i = 0; i < depth; i++)
        cout << "   ";

    cout << "|--" << root->value << endl;

    print(root->left, depth + 1);
}




void countAndPrintBranches(node* root, int level, int target) {
    if (root == nullptr)
        return;

    if (level == 0) {
        // Достигли целевого уровня, выводим значение текущего узла
        if (root->value == target) {
            cout << root->value << " ";
        }
        return;
    }

    // Рекурсивно вызываем функцию countAndPrintBranches() для всех дочерних элементов на уровне level - 1
    countAndPrintBranches(root->left, level - 1, target);
    countAndPrintBranches(root->right, level - 1, target);
}
int main() {
    setlocale(0, "");

    // Создание корня дерева
    node* root = nullptr;

    // Ввод целых чисел и построение дерева
    int num;
    cout << "Введите целые числа (ввод завершится при вводе отрицательного числа):" << endl;
    while (cin >> num && num >= 0) {
        root = insert(root, num);
    }

    // Вывод элементов дерева
    cout << "Элементы дерева в порядке возрастания:" << endl;
    print(root);

    int level;
    cout << "Введите уровень: ";
    cin >> level;

    int target;
    cout << "Введите число: ";
    cin >> target;

    cout << "Элементы ветвей на уровне " << level << ", содержащие число " << target << ":" << endl;
    countAndPrintBranches(root, level, target);
    // Освобождение памяти, удаляя дерево
    delete root;

    return 0;
}