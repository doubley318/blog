**Clash for Linux**

**下面有两种方法，方法一比较繁琐，不推荐，可以直接进行方法二**
# clash 方法1

1. 下载[clash](https://github.com/Dreamacro/clash/releases)，一般选择：clash-linux-amd64-v1.8.0.gz
2. 创建一个名为clash的文件夹
3. 解压clash，并重命名为clash
4. 修改clash权限
   ```
   sudo chmod +x /usr/bin/clash
   ```
5. 获取订阅地址：
    $订阅地址$，命名为sockboom
6. 下载配置：
   ```
   wget -O config.yaml $订阅地址?clash=1&log-level=info$
   ```
   得到三个文件分别为：
    config.yaml
    wget-log
    clash-linux-amd64
7. 删除config.yaml
8.  将前面的文件sockboom复制到这边来，并改名为config.yaml
9.  修改权限：chmod +x clash-linux-amd64
10. ./clash-linux-amd64 -d .
11. 打开:http://clash.razord.top/#/proxies进行验证
12. 打开设置：网络->网络代理
    ```
    HTTP代理：127.0.0.1    端口7890
    HTTPS代理：127.0.0.1  端口7890
    socks主机：127.0.0.1    端口7891
    忽略主机：localhost, 127.0.0.0/8, ::1
    ```
13. 将clash移动到/usr/bin/
14. 检查clash是否安装成功`clash -v`
15. 默认配置目录是 $HOME/.config/clash，将`config.yaml`, `cache.db`,`Country.mmdb`复制到此目录来
16. 如果要使用其他目录，可以使用 -d 控制配置目录，例如，您可以使用当前目录作为配置目录`clash -d .`
17. 在 /lib/systemd/system/ 目录下创建 `clash@.service` 文件写入：
    ```
    [Unit]
    Description=A rule based proxy in Go for %i.
    After=network.target

    [Service]
    Type=simple
    User=%i
    Restart=on-abort
    ExecStart=/usr/bin/clash

    [Install]
    WantedBy=multi-user.target
    ```
18. system
    ```
    systemctl daemon-reload
    systemctl start clash@a307
    systemctl enable clash@a307
    ```

# clash 方法2
前面那个设置很麻烦，而且也没有UI界面，所以在经过多次查找，我发现了有人把windows版本的也写了Linux版本：

https://github.com/Fndroid/clash_for_windows_pkg/releases

找到Clash.for.Windows-$version$-x64-linux.tar.gz

然后下载安装，下载完成后是一个压缩包，解压，并执行其中的 cfw 即可。

## start with Linux don't work

Solution:添加`/etc/xdg/autostart/cfw.desktop`，内容如下：

```bash
[Desktop Entry]
Name=CFW
Name[zh_CN]=Clash for windwos
GenericName=Clash for windows
GenericName[zh_CN]=Clash for windows
Comment=Start Clash for windows
Comment[zh_CN]=启动Clash for windows
Exec=[your cfw's location]
Icon=[your cfw's location]
Terminal=false
Type=Application
Categories=System;Utility;
StartupNotify=false
X-GNOME-AutoRestart=false
X-GNOME-Autostart-Notify=false
X-KDE-autostart-after=panel
X-KDE-StartupNotify=false
```
