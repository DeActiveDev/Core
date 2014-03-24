/*Copyright (C) 2014 SkyMist Project.
*
* This file is NOT free software. Third-party users can NOT redistribute it or modify it :). 
* If you find it, you are either hacking something, or very lucky (presuming someone else managed to hack it).
*/

#include "Player.h"
#include "PlayerMovementMgr.h"
#include "AccountMgr.h"
#include "AchievementMgr.h"
#include "ArenaTeam.h"
#include "ArenaTeamMgr.h"
#include "Battlefield.h"
#include "BattlefieldMgr.h"
#include "BattlefieldWG.h"
#include "Battleground.h"
#include "BattlegroundMgr.h"
#include "CellImpl.h"
#include "Channel.h"
#include "ChannelMgr.h"
#include "CharacterDatabaseCleaner.h"
#include "Chat.h"
#include "Common.h"
#include "ConditionMgr.h"
#include "CreatureAI.h"
#include "DatabaseEnv.h"
#include "DB2Stores.h"
#include "DisableMgr.h"
#include "Formulas.h"
#include "GameEventMgr.h"
#include "GossipDef.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "Group.h"
#include "GroupMgr.h"
#include "Guild.h"
#include "GuildMgr.h"
#include "InstanceSaveMgr.h"
#include "InstanceScript.h"
#include "LFGMgr.h"
#include "Language.h"
#include "Log.h"
#include "MapInstanced.h"
#include "MapManager.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Opcodes.h"
#include "OutdoorPvP.h"
#include "OutdoorPvPMgr.h"
#include "Pet.h"
#include "QuestDef.h"
#include "ReputationMgr.h"
#include "SkillDiscovery.h"
#include "SocialMgr.h"
#include "Spell.h"
#include "SpellAuraEffects.h"
#include "SpellAuras.h"
#include "SpellMgr.h"
#include "Transport.h"
#include "UpdateData.h"
#include "UpdateFieldFlags.h"
#include "UpdateMask.h"
#include "Util.h"
#include "Vehicle.h"
#include "Weather.h"
#include "WeatherMgr.h"
#include "World.h"
#include "WorldPacket.h"
#include "WorldSession.h"
#include "MovementStructures.h"
#include "Config.h"
#include "GameObjectAI.h"

void WorldSession::SendNewWorld(WorldLocation const &location)
{
    if(sMapMgr->IsValidMapCoord(location))
    {
        WorldPacket worldPosition(SMSG_NEW_WORLD, 20);
        worldPosition << location.GetMapId() << location.GetPositionY() << location.GetPositionZ() << location.GetOrientation() << location.GetPositionX();
        SendPacket(&worldPosition);
    }
    else
    {
        WorldPacket worldAbort(SMSG_NEW_WORLD_ABORT);
        SendPacket(&worldAbort);
    }
}
