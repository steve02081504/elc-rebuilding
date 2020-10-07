### 快速PR
[alex to steve](https://github.com/steve02081504/ELC/compare/master...alex0125z:master)  
[steve to alex](https://github.com/alex0125z/ELC/compare/master...steve02081504:master)  
  
[翱翔的黑鹰 to steve](https://github.com/steve02081504/ELC/compare/master...AXDHY:master)  
[steve to 翱翔的黑鹰](https://github.com/AXDHY/ELC/compare/master...steve02081504:master)  

____

[![996.icu]( https://img.shields.io/badge/link-996.icu-red.svg )]( https://996.icu )
本项目支持anti-996，请所有国产浏览器拉黑并禁止访问，谢谢  
### 介绍  
ELC是一款正在开发中的解释型语言  
目前没有官方文档，作者们正在从自制轮子开始写解释器（太坏了，准备拿枪对线）  

### 特性  
 - 可以跨平台运行  
即使使用其他语言所写的库，只要库本身按照ELC规定格式构建并支持目标平台，那么代码便仍然是跨平台的  

 - 高度复用  
当两个ELC程序都依赖一个第三方库时，本机上便只会留有一份库文件：这使得可执行文件占地更小  

 - 依赖项的自行安装&更新  
不必在代码中包含依赖项的安装代码与更新检查，ELC底层将在载入代码时自动完成这一切  

 - 一切都是数据  
变量、名称空间、函数、类型定义——一切都是数据，一切都可以在运行时加载、执行、修改、保存、通过互联网跨平台传输，或通过各种渠道下载并在运行时替换本地定义——想怎么玩都行  

 - 没有编译期，但仍然可以读入时检查  
在代码从文本转换为nodesave时通过自定义的函数修改函数或名称空间等定义来模拟宏，或是通过转换时的报错来实现读入时检查的功能——灵活度与安全性兼得。  

 - 视界优化&结果复用  
通过保存可能性并使其在被观测时再坍缩以规避不必要的计算与副作用，通过node的特殊机制来复用大多数的计算结果  

 - 垃圾回收  
使用有史以来最垃圾的垃圾回收机制来自动回收内存垃圾：当然，你仍然可以操作内存，如果你需要的话。  

### [贡献者名单]( CONTRIBUTORS.md )  
请点击上方标题  

### 我该如何参与开发？  
很不幸作者写到这里就去吃午饭了  
请等待文档更新  

默认内容：  
[修改你的副本]( https://github.com/steve02081504/ELC/fork )并[向我的项目提交PR]( https://github.com/steve02081504/ELC/compare )
以参与其中（[github帮助页面]( https://help.github.com/cn )）  
或者来[help wanted]( ./md/help_wanted.md )部分解决高优先级或我暂时没时间解决的问题！  
不论以何种方式参与，[贡献者名单]( CONTRIBUTORS.md )上都会留下你的名字/ID（你也可以要求匿名）  
（当然，对于被拒绝的PR，我会给出拒绝的理由，如果你足够努力，即使是被拒绝也不影响你的名字/ID进入名单——并附上你的分支版本链接）  

### [关于我]( https://steve02081504.github.io/about )  
请点击上方标题  

### 最后  
感谢你看到这里  
:)  
你可能还对[Taromati2]( https://github.com/steve02081504/Taromati2 )感兴趣？  
