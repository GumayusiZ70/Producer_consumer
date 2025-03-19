📌 代码框架

📂 producer_consumer_project  # 项目根目录
├── 📂 inc                     # 头文件（声明）
│   ├── TaskQueue.h            # 任务队列类（生产者-消费者共享）
│   ├── Producer.h             # 生产者类
│   ├── Consumer.h             # 消费者类
│   ├── ProducerConsumerManager.h  # 生产者-消费者管理类
├── 📂 src                     # 源代码（实现）
│   ├── TaskQueue.cpp          # 任务队列实现
│   ├── Producer.cpp           # 生产者实现
│   ├── Consumer.cpp           # 消费者实现
│   ├── ProducerConsumerManager.cpp  # 管理类实现
├── main.cpp                   # 入口函数
├── CMakeLists.txt              # CMake 构建配置


生产者-消费者问题：C++ 设计思路与框架结构
你的项目采用 C++11 及以上，利用封装、继承、多态等思想，模块化实现生产者-消费者模型，使得后续功能扩展更加方便。在 Windows（VSCode）和 Ubuntu（Clion）上均可运行。

📌 设计目标
任务队列（TaskQueue）：共享的缓冲区，使用**互斥锁（mutex）和条件变量（condition_variable）**来同步访问，确保线程安全。
生产者（Producer）：不断生成任务，放入任务队列，等待消费者处理。
消费者（Consumer）：不断从任务队列取出任务进行消费。
管理类（ProducerConsumerManager）：管理生产者和消费者的生命周期，协调启动和终止
