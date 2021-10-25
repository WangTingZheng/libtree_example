# libtree example

此项目是Linux内核风格的搜索树库[libtree](https://github.com/fbuihuu/libtree)的用例，官方仓库没有给例子，README文档的简单例子即不完整又不准确，也没有解释为什么使用方法如此奇怪的原因，所以我写了这个小例子来说明libtree中bstree的使用，更详细的文章请看[Linux内核风格的搜索树库的简单使用](https://zhuanlan.zhihu.com/p/425254012)

## 安装库

```bash
git clone https://github.com/fbuihuu/libtree
cd libtree
make
make install
ldconfig
```

## 编译运行例子

```bash
git clone https://github.com/WangTingZheng/libtree_example
cd libtree_example
gcc -o example example.c /usr/local/lib/libtree.so
./example
```

无报错说明运行通过
