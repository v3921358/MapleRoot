#pragma once
#include <chrono>
#include <mutex>
#include <thread>
#include "Discord/discord.h"
#include <csignal>
#include <iostream>

class DiscordRichPresence {
public:
	static DiscordRichPresence& getInstance() {
		static DiscordRichPresence instance;
		return instance;
	}

	DiscordRichPresence(const DiscordRichPresence&) = delete;
	DiscordRichPresence& operator=(const DiscordRichPresence&) = delete;
	DiscordRichPresence() {
		if (!Discord_Initialize(6, DiscordCreateFlags_NoRequireDiscord))
		{
			return;
		}

		isInitialized = true;
	}

	void updatePresence(const int jobCode, int level, const char* charName) {
		std::lock_guard<std::mutex> lock(mutex);
		this->jobCode = getJobName(jobCode);
		this->level = level;
		this->charName = charName;
		this->isLoggedIn = true;
	}

	void setJobCode(const int jobCode) {
		std::lock_guard<std::mutex> lock(mutex);
		this->jobCode = getJobName(jobCode);
	}

	void setLevel(int level) {
		std::lock_guard<std::mutex> lock(mutex);
		this->level = level;
	}

	void setCharacterName(const char* charName) {
		std::lock_guard<std::mutex> lock(mutex);
		this->charName = charName;
	}

	void setIsLoggedIn(bool isLoggedIn) {
		std::lock_guard<std::mutex> lock(mutex);
		this->isLoggedIn = isLoggedIn;
	}

	void beginUpdates() {
		if (!isInitialized || running)
		{
			return;
		}

		running = true;
		level = 0;
		isLoggedIn = false;
		jobCode = getJobName(100);

		auto now = std::chrono::system_clock::now();
		auto duration = now.time_since_epoch();
		auto epoch = std::chrono::duration_cast<std::chrono::seconds>(duration).count();

		activity.GetTimestamps().SetStart(epoch);

		activity.SetDetails("");
		activity.SetState("");
		activity.GetAssets().SetSmallImage("");
		activity.GetAssets().SetSmallText("");
		activity.GetAssets().SetLargeImage("");
		activity.GetAssets().SetLargeText("");
		activity.SetName("");
		activity.SetType(discord::ActivityType::Playing);

		core->ActivityManager().UpdateActivity(activity, [](discord::Result result){  });

		std::signal(SIGINT, [](int) { getInstance().running = false; });

		// Start the thread
		thread = std::thread(&DiscordRichPresence::updateLoop, this);
	}

private:
	std::thread thread;
	std::mutex mutex;
	bool running;
	std::string jobCode;
	int level;
	bool isLoggedIn;
	bool isInitialized;
	std::string charName;
	discord::Core* core{};
	discord::Activity activity{};

	void updateLoop() {
		while (running) {
			Discord_UpdatePresence();

			// Sleep for some time (e.g., 15 seconds)
			std::this_thread::sleep_for(std::chrono::seconds(15));
		}
	}

	bool Discord_Initialize(discord::ClientId clientId, EDiscordCreateFlags flags)
	{
		auto result = discord::Core::Create(clientId, flags, &core);

		if (result != discord::Result::Ok)
		{
			return false;
		}

		return true;
	}

	void Discord_UpdatePresence()
	{
		core->RunCallbacks();
		if (isLoggedIn) {
			std::lock_guard<std::mutex> lock(mutex);
			std::stringstream ss;
			ss << charName << " (Lv. " << this->level << ")";

			activity.GetAssets().SetSmallImage(this->jobCode.c_str());
			activity.GetAssets().SetSmallText(this->jobCode.c_str());
			activity.GetAssets().SetLargeImage("");
			activity.GetAssets().SetLargeText("");
			activity.SetDetails(ss.str().c_str());
			//activity = defaultActivity;
		}
		else
		{
			std::lock_guard<std::mutex> lock(mutex);
			activity.SetDetails("");
			//activity.SetState("");
			activity.GetAssets().SetSmallImage("");
			activity.GetAssets().SetSmallText("");
			activity.GetAssets().SetLargeImage("");
			activity.GetAssets().SetLargeText("");
			//activity = characterActivity();
		}
		core->ActivityManager().UpdateActivity(activity, [](discord::Result result) {});
	}

	static const char* getJobName(int jobId)
	{
		switch (jobId)
		{
		case 0:
			return "beginner";
		case 100:
			return "warrior";
		case 110:
			return "fighter";
		case 111:
			return "crusader";
		case 112:
			return "hero";
		case 120:
			return "page";
		case 121:
			return "white_knight";
		case 122:
			return "paladin";
		case 130:
			return "spearman";
		case 131:
			return "dragon_knight";
		case 132:
			return "dark_knight";
		case 200:
			return "mage";
		case 210:
			return "fp_wizard";
		case 211:
			return "fp_mage";
		case 212:
			return "fp_archmage";
		case 220:
			return "il_wizard";
		case 221:
			return "il_mage";
		case 222:
			return "il_archmage";
		case 230:
			return "cleric";
		case 231:
			return "priest";
		case 232:
			return "bishop";
		case 300:
			return "bowman";
		case 310:
			return "hunter";
		case 311:
			return "ranger";
		case 312:
			return "bowmaster";
		case 320:
			return "crossbowman";
		case 321:
			return "sniper";
		case 322:
			return "marksman";
		case 400:
			return "thief";
		case 410:
			return "assassin";
		case 411:
			return "hermit";
		case 412:
			return "nightlord";
		case 420:
			return "bandit";
		case 421:
			return "chief_bandit";
		case 422:
			return "shadower";
		case 500:
			return "pirate";
		case 510:
			return "brawler";
		case 511:
			return "marauder";
		case 512:
			return "buccaneer";
		case 520:
			return "gunslinger";
		case 521:
			return "outlaw";
		case 522:
			return "corsair";
		case 700:
			return "super_beginner";
		case 900:
			return "game_master";
		case 910:
			return "game_master";
		case 1000:
			return "noblesse";
		case 1100:
			return "dawn_warrior";
		case 1110:
			return "dawn_warrior";
		case 1111:
			return "dawn_warrior";
		case 1112:
			return "dawn_warrior";
		case 1200:
			return "blaze_wizard";
		case 1210:
			return "blaze_wizard";
		case 1211:
			return "blaze_wizard";
		case 1212:
			return "blaze_wizard";
		case 1300:
			return "wind_archer";
		case 1310:
			return "wind_archer";
		case 1311:
			return "wind_archer";
		case 1312:
			return "wind_archer";
		case 1400:
			return "night_walker";
		case 1410:
			return "night_walker";
		case 1411:
			return "night_walker";
		case 1412:
			return "night_walker";
		case 1500:
			return "thunder_breaker";
		case 1510:
			return "thunder_breaker";
		case 1511:
			return "thunder_breaker";
		case 1512:
			return "thunder_breaker";
		case 2000:
			return "legend";
		case 2100:
			return "aran";
		case 2110:
			return "aran";
		case 2111:
			return "aran";
		case 2112:
			return "aran";
		default:
			return "logo";
		}
	}
};

