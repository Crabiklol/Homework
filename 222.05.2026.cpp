#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <map>
#include <functional>  
#include <stdexcept>


class IMessageChannel {
public:
    virtual ~IMessageChannel() = default;
    virtual void send(const std::string& payload) const = 0;
};

class TelegramSender : public IMessageChannel {
public:
    void send(const std::string& p) const override {
        std::cout << "  [Telegram] " << p << "\n";
    }
};

class WhatsAppSender : public IMessageChannel {
public:
    void send(const std::string& p) const override {
        std::cout << "  [WhatsApp] " << p << "\n";
    }
};

class DiscordSender : public IMessageChannel {
public:
    void send(const std::string& p) const override {
        std::cout << "  [Discord]   " << p << "\n";
    }
};


class Message {
protected:
    std::shared_ptr<IMessageChannel> channel_;
public:
    explicit Message(std::shared_ptr<IMessageChannel> channel)
        : channel_(std::move(channel)) {
    }
    virtual ~Message() = default;

    void setChannel(std::shared_ptr<IMessageChannel> newChannel) {
        channel_ = std::move(newChannel);
    }

    virtual void dispatch() const = 0;
};

class TextMessage : public Message {
    std::string content_;
public:
    TextMessage(std::string text, std::shared_ptr<IMessageChannel> ch)
        : Message(std::move(ch)), content_(std::move(text)) {
    }

    void dispatch() const override {
        channel_->send("[TEXT] " + content_);
    }
};

class VoiceMessage : public Message {
    std::string audioRef_;
public:
    VoiceMessage(std::string audio, std::shared_ptr<IMessageChannel> ch)
        : Message(std::move(ch)), audioRef_(std::move(audio)) {
    }

    void dispatch() const override {
        channel_->send("[VOICE] " + audioRef_);
    }
};

class VideoMessage : public Message {
    std::string videoRef_;
public:
    VideoMessage(std::string video, std::shared_ptr<IMessageChannel> ch)
        : Message(std::move(ch)), videoRef_(std::move(video)) {
    }

    void dispatch() const override {
        channel_->send("[VIDEO] " + videoRef_);
    }
};


class ChannelFactory {
    std::map<std::string, std::function<std::shared_ptr<IMessageChannel>()>> registry_;
public:
    ChannelFactory() {
        registry_["tg"] = [] { return std::make_shared<TelegramSender>(); };
        registry_["wa"] = [] { return std::make_shared<WhatsAppSender>(); };
        registry_["dc"] = [] { return std::make_shared<DiscordSender>(); };
    }

    std::shared_ptr<IMessageChannel> create(const std::string& type) const {
        auto it = registry_.find(type);
        if (it == registry_.end())
            throw std::invalid_argument("Unknown channel");
        return it->second();
    }
};


int main() {
    setlocale(LC_ALL, "Russian");

    ChannelFactory factory;
    std::vector<std::shared_ptr<Message>> inbox;

    
    inbox.push_back(std::make_shared<TextMessage>("Привет, как дела?", factory.create("tg")));
    inbox.push_back(std::make_shared<TextMessage>("Встреча в 18:00", factory.create("wa")));
    inbox.push_back(std::make_shared<VoiceMessage>("voice_note_01.opus", factory.create("tg")));
    inbox.push_back(std::make_shared<VideoMessage>("presentation_v2.mp4", factory.create("dc")));
    inbox.push_back(std::make_shared<TextMessage>("Критический баг!", factory.create("dc")));
    inbox.push_back(std::make_shared<VoiceMessage>("interview_rec.wav", factory.create("wa")));

    std::cout << "=== Отправка сообщений ===\n";
    for (const auto& msg : inbox) {
        msg->dispatch();
    }

   
    std::cout << "\n=== Смена канала ===\n";
    auto msg = std::make_shared<TextMessage>("Срочно!", factory.create("tg"));
    msg->dispatch();
    msg->setChannel(factory.create("dc"));
    msg->dispatch();

    return 0;
}
