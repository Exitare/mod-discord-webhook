#include "WorldScript.h"
#include "Config.h"
#include "WebhookMgr.h"

// Add player scripts
class WebhookServerScripts : public WorldScript
{
public:
    WebhookServerScripts() : WorldScript("WebhookServerScripts") { }

    void OnStartup() override
    {
        std::string webhookUrl = sConfigMgr->GetOption<std::string>("Webhook.URL", "");
        if (std::empty(webhookUrl)) {
            LOG_ERROR("server.worldserver", "Webhook url is empty. Disabling module. Please provide a valid url.");
            return;
        }

        LOG_INFO("server.worldserver", ">> Webhook module initialized.");
        sWebhookMgr->SetWebhookUrl(webhookUrl);
        sWebhookMgr->Start();
    }

    void OnShutdown() override
    {
        LOG_INFO("server.worldserver", "Stopping webhook queue...");
        sWebhookMgr->Stop();
        return;
    }
};

// Add all scripts in one
void AddWebhookServerScripts()
{
    new WebhookServerScripts();
}
