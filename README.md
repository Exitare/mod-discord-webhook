
# AzerothCore Webhook Module

Welcome to the webhook module for AzerothCore. 
This module will add functionality to let you send messages to webhook endpoints (e.g. Discord).



## Installation
Please use this link for guidance how to install a module:  
```https://www.azerothcore.org/wiki/installing-a-module```

## Usage

- Copy the modules config and remove the .dist extension. 
- Add your webhook url to the config. Save and restart your server


## Example use 

```cpp
#include "ScriptMgr.h"
#include "Player.h"
#include "Config.h"
#include "Chat.h"
#include "WebhookMgr.h" // add the mgr


// Add player scripts
class WebhookPlayerLogin : public PlayerScript
{
public:
    WebhookPlayerLogin() : PlayerScript("MyWebhookPlayerScript") { }

    void OnLogin(Player* player) override
    {
       std::stringstream ss;
       ss << "Player " << player->GetName() << " just signed in.";

       std::string message = ss.str();

       sWebhookMgr->ScheduleMessage(message); // Schedule the message
    }
};

// Add all scripts in one
void AddWebhookPlayerScripts()
{
    new WebhookPlayerLogin();
}


```

Add the script to the script loader. Can also be added in any other script loader.  

webhook_loader.cpp
```cpp
void AddWebhookPlayerScripts();

void Addacore_webhooksScripts()
{
    AddWebhookPlayerScripts();
    AddWebhookServerScripts();
}
```