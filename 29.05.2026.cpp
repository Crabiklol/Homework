//1
struct RealSubject : IService {
    void execute() override { std::cout << "RealSubject: Executing\n"; }
    std::string getData() const override { return "Real Data"; }
};

struct MinimalProxy : IService {
    std::unique_ptr<RealSubject> real_;

    MinimalProxy() : real_(std::make_unique<RealSubject>()) {}

    void execute() override {
        std::cout << "Proxy: Before call\n";
        real_->execute();
        std::cout << "Proxy: After call\n";
    }
    std::string getData() const override { return real_->getData(); }
};

//2
struct Image {
    std::string filename_;
    explicit Image(const std::string& name) : filename_(name) {
        std::cout << "Image: Loading " << filename_ << " from disk...\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // имитация загрузки
    }
    void display() const { std::cout << "Image: Displaying " << filename_ << "\n"; }
};

struct ImageProxy : IService {
    std::unique_ptr<Image> image_;
    std::string filename_;
    bool loaded_ = false;

    explicit ImageProxy(const std::string& name) : filename_(name) {}

    void execute() override { display(); } // для совместимости с IService
    std::string getData() const override { return filename_; }

    void display() {
        if (!loaded_) {
            image_ = std::make_unique<Image>(filename_);
            loaded_ = true;
        }
        image_->display();
    }
};

//3
struct Database : IService {
    void execute() override { std::cout << "DB: Running query\n"; }
    std::string getData() const override { return "Sensitive DB Data"; }
};

struct DatabaseProxy : IService {
    std::unique_ptr<Database> db_;
    std::string role_;

    DatabaseProxy(const std::string& role) : db_(std::make_unique<Database>()), role_(role) {}

    void execute() override {
        if (role_ == "admin") {
            db_->execute();
        } else {
            std::cout << "Proxy: Access denied for role '" << role_ << "'\n";
        }
    }
    std::string getData() const override { return (role_ == "admin") ? db_->getData() : "Forbidden"; }
};

//4
struct LoggingProxy : IService {
    std::unique_ptr<IService> real_;
    int callCount_ = 0;

    explicit LoggingProxy(std::unique_ptr<IService> real) : real_(std::move(real)) {}

    void execute() override {
        auto start = std::chrono::steady_clock::now();
        real_->execute();
        auto end = std::chrono::steady_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
        callCount_++;
        std::cout << "Log: Call #" << callCount_ << ", Duration: " << duration << " μs\n";
    }
    std::string getData() const override { return real_->getData(); }
};

//5
struct HeavyCalcService : IService {
    void execute() override { std::cout << "Calc: Computing...\n"; std::this_thread::sleep_for(std::chrono::milliseconds(200)); }
    std::string getData() const override { return "Computed Result"; }
};

struct CacheProxy : IService {
    std::unique_ptr<HeavyCalcService> real_;
    std::unordered_map<std::string, std::string> cache_;

    explicit CacheProxy(std::unique_ptr<HeavyCalcService> real) : real_(std::move(real)) {}

    void execute() override { real_->execute(); }
    
    std::string getData() override {
        const std::string key = "default"; // в реальности зависит от параметров
        if (cache_.find(key) == cache_.end()) {
            cache_[key] = real_->getData();
            std::cout << "Cache: MISS. Computing & storing.\n";
        } else {
            std::cout << "Cache: HIT. Returning cached.\n";
        }
        return cache_[key];
    }
};

//6
struct API { virtual ~API()=default; virtual void fetch(const std::string& endpoint)=0; };
struct RealAPI : API { void fetch(const std::string& ep) override { std::cout << "RealAPI: GET " << ep << "\n"; } };
struct APIGatewayProxy : API {
    std::unique_ptr<RealAPI> api_;
    std::unordered_map<std::string, int> requestLog_;
    int limit_ = 5;
    explicit APIGatewayProxy(std::unique_ptr<RealAPI> api) : api_(std::move(api)) {}
    void fetch(const std::string& ep) override {
        if (!validateToken()) { std::cout << "Auth Failed\n"; return; }
        requestLog_[ep]++;
        if (requestLog_[ep] > limit_) { std::cout << "Rate limit exceeded\n"; return; }
        std::cout << "Log: " << ep << " at " << std::chrono::system_clock::now().time_since_epoch().count() << "\n";
        api_->fetch(ep);
    }
    bool validateToken() { return true; /* имитация */ }
};

//12
template<typename T>
struct SmartProxy {
    std::shared_ptr<T> obj_;
    std::chrono::steady_clock::time_point lastAccess_;
    int activeRefs_ = 0;
 
};

//14
struct ThreadSafeProxy : IService {
    std::unique_ptr<IService> real_;
    std::mutex mtx_;
    bool busy_ = false;

    explicit ThreadSafeProxy(std::unique_ptr<IService> real) : real_(std::move(real)) {}

    void execute() override {
        std::lock_guard<std::mutex> lock(mtx_);
        if (busy_) { std::cout << "Proxy: Busy. Queueing...\n"; return; }
        busy_ = true;
        real_->execute();
        busy_ = false;
    }
    std::string getData() const override { 
        std::lock_guard<std::mutex> lock(mtx_); 
        return real_->getData(); 
    }
};

//16

struct LoggingDecorator : IService {
    std::shared_ptr<IService> wrap_;
    explicit LoggingDecorator(std::shared_ptr<IService> w) : wrap_(w) {}
    void execute() override { std::cout << "[LOG] Start\n"; wrap_->execute(); std::cout << "[LOG] End\n"; }
    std::string getData() const override { return wrap_->getData(); }
};

//17
enum class ProxyType { DATABASE, FILE, API };
struct ProxyFactory {
    static std::shared_ptr<IService> create(ProxyType type) {
        switch(type) {
            case ProxyType::DATABASE: return std::make_shared<DatabaseProxy>("admin");
            case ProxyType::FILE:     return std::make_shared<ProtectedFileSystem>(...);
            case ProxyType::API:      return std::make_shared<APIGatewayProxy>(...);
            default: throw std::invalid_argument("Unknown proxy");
        }
    }
};

//20
struct CloudStorage : IService {
    virtual ~CloudStorage()=default;
    virtual void upload(const std::string& path, const std::string& data) = 0;
    virtual std::string download(const std::string& path) = 0;
};

struct RealCloudStorage : CloudStorage {
    void upload(const std::string& p, const std::string& d) override { 
        std::cout << "RealCloud: Uploading " << p << " (" << d.size() << "B)\n"; 
    }
    std::string download(const std::string& p) override { 
        std::cout << "RealCloud: Downloading " << p << "\n"; 
        return "BinaryData_" + p; 
    }
    void execute() override {} // заглушка для IService
    std::string getData() const override { return "Cloud"; }
};

struct CloudStorageProxy : CloudStorage {
    std::shared_ptr<RealCloudStorage> real_;
    std::unordered_map<std::string, std::string> cache_;
    bool isAuthenticated_ = false;
    std::mutex mtx_;
    size_t maxFileSize_ = 1024 * 1024; // 1MB

    explicit CloudStorageProxy(std::shared_ptr<RealCloudStorage> real) : real_(real) {}

    void authenticate(const std::string& token) { isAuthenticated_ = (token == "valid_token"); }

    void upload(const std::string& path, const std::string& data) override {
        if (!isAuthenticated_) throw std::runtime_error("Unauthorized");
        if (data.size() > maxFileSize_) throw std::runtime_error("File too large");
        std::lock_guard<std::mutex> lock(mtx_);
        cache_.erase(path); // invalidate cache
        real_->upload(path, data);
        std::cout << "Log: Upload " << path << " at " << std::chrono::system_clock::now().time_since_epoch().count() << "\n";
    }

    std::string download(const std::string& path) override {
        if (!isAuthenticated_) throw std::runtime_error("Unauthorized");
        std::lock_guard<std::mutex> lock(mtx_);
        if (cache_.find(path) == cache_.end()) {
            std::cout << "Cache: MISS. Lazy loading from cloud.\n";
            cache_[path] = real_->download(path);
        } else {
            std::cout << "Cache: HIT.\n";
        }
        return cache_[path];
    }

    void execute() override {}
    std::string getData() const override { return "ProxyCloud"; }
};

