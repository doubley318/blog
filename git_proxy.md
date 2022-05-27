当我使用`clash-for-windows`简称`cfw`的时候，发现：
```bash
rsy@rsy:~$ git clone https://github.com/NVIDIA/cuda-samples.git
正克隆到 'cuda-samples'...
remote: Enumerating objects: 9693, done.
^C收对象中:   8% (834/9693), 3.54 MiB | 3.51 MiB/s
rsy@rsy:~$ sudo git clone https://github.com/NVIDIA/cuda-samples.git
正克隆到 'cuda-samples'...
fatal: 无法访问 'https://github.com/NVIDIA/cuda-samples.git/'：Failed to connect to github.com port 443: 拒绝连接
```
相关的代理感觉一切正常，因为终端`git`也是可以使用的，然后，浏览器也是可以使用的，唯有`sudo git`是不可以使用的。

经过分析之后，发现应该是`sudo git`使用的代理不正确，或者是没有使用代理，所以要更改`sudo git`的代理：
```bash
# 清除代理设置：命令如下
git config --global --unset http.proxy
git config --global --unset https.proxy

# 重新设置代理：命令如下
git config --global http.proxy http://127.0.0.1:7890
git config --global https.proxy http://127.0.0.1:7890
```

然后：
```bash
rsy@rsy:~$ sudo git clone https://github.com/NVIDIA/cuda-samples.git
正克隆到 'cuda-samples'...
remote: Enumerating objects: 9693, done.
^C收对象中:  15% (1470/9693), 8.93 MiB | 4.41 MiB/s
```

**成功！！！！！！！！！！**