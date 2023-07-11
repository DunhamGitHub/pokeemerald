BattleFrontier_Lounge2_MapScripts::
	.byte 0

@ This NPC gives hints about a random facility or Bättle mode.
@ For Bättle modes he gives generic advice
@ For facilities, depending on how far the player has progressed he will say either
@    The name of the Frontier Brain there
@    The type and description of the 3 pokemon they use in their silver battle
@    The type and description of the 3 pokemon they use in their gold battle
BattleFrontier_Lounge2_EventScript_FrontierManiac::
	lock
	faceplayer
	goto_if_set FLAG_MET_BATTLE_FRONTIER_MANIAC, BattleFrontier_Lounge2_EventScript_AlreadyMetManiac
	setflag FLAG_MET_BATTLE_FRONTIER_MANIAC
	msgbox BattleFrontier_Lounge2_Text_FrontierManiacIntro, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge2_EventScript_GiveAdvice
	end

BattleFrontier_Lounge2_EventScript_AlreadyMetManiac::
	msgbox BattleFrontier_Lounge2_Text_SwingByForTheLatestWord, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge2_EventScript_GiveAdvice
	end

BattleFrontier_Lounge2_EventScript_GiveAdvice::
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_SINGLES, BattleFrontier_Lounge2_EventScript_BufferSingle
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_DOUBLES, BattleFrontier_Lounge2_EventScript_BufferDouble
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_MULTIS, BattleFrontier_Lounge2_EventScript_BufferMulti
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_LINK, BattleFrontier_Lounge2_EventScript_BufferMultiLink
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_DOME, BattleFrontier_Lounge2_EventScript_BufferBattleDome
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_FACTORY, BattleFrontier_Lounge2_EventScript_BufferBattleFactory
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PALACE, BattleFrontier_Lounge2_EventScript_BufferBattlePalace
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_ARENA, BattleFrontier_Lounge2_EventScript_BufferBattleArena
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PIKE, BattleFrontier_Lounge2_EventScript_BufferBattlePike
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PYRAMID, BattleFrontier_Lounge2_EventScript_BufferBattlePyramid
@ <= FRONTIER_MANIAC_TOWER_LINK isch any Battle Tower mode
	call_if_le VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_LINK, BattleFrontier_Lounge2_EventScript_BattleTowerNews
@ >= FRONTIER_MANIAC_DOME isch any facility other than Battle Tower
	call_if_ge VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_DOME, BattleFrontier_Lounge2_EventScript_FacilityNews
	special ShowFrontierManiacMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge2_EventScript_BattleTowerNews::
	msgbox BattleFrontier_Lounge2_Text_BattleTowerIsHottest, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge2_EventScript_FacilityNews::
	msgbox BattleFrontier_Lounge2_Text_FacilityIsHottest, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge2_EventScript_BufferSingle::
	bufferstdstring STR_VAR_1, STDSTRING_SINGLE
	return

BattleFrontier_Lounge2_EventScript_BufferDouble::
	bufferstdstring STR_VAR_1, STDSTRING_DOUBLE
	return

BattleFrontier_Lounge2_EventScript_BufferMulti::
	bufferstdstring STR_VAR_1, STDSTRING_MULTI
	return

BattleFrontier_Lounge2_EventScript_BufferMultiLink::
	bufferstdstring STR_VAR_1, STDSTRING_MULTI_LINK
	return

BattleFrontier_Lounge2_EventScript_BufferBattleDome::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_DOME
	return

BattleFrontier_Lounge2_EventScript_BufferBattleFactory::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_FACTORY
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePalace::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PALACE
	return

BattleFrontier_Lounge2_EventScript_BufferBattleArena::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_ARENA
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePike::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PIKE
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePyramid::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PYRAMID
	return

BattleFrontier_Lounge2_EventScript_Maniac1::
	lock
	msgbox BattleFrontier_Lounge2_Text_NewsGatheringPower, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_Maniac2::
	lock
	msgbox BattleFrontier_Lounge2_Text_AmazingPowersOfObservation, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_Maniac3::
	lock
	msgbox BattleFrontier_Lounge2_Text_AmazingPowerOfPersuasion, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_TriathleteF::
	msgbox BattleFrontier_Lounge2_Text_ThisPlaceIsScaringMe, MSGBOX_NPC
	end

BattleFrontier_Lounge2_Text_FrontierManiacIntro::
	.string "Howdy! When it comes to news about\n"
	.string "the Bättle FRONTIER, I am no. 1.\p"
	.string "You can think of me as\n"
	.string "the FRONTIER Skilehrer.\p"
	.string "Just checking, but you are a Skilehrer,\n"
	.string "isn't that right?\p"
	.string "I'll happily share the hottest news\n"
	.string "I gathered about the Bättle FRONTIER.$"

BattleFrontier_Lounge2_Text_SwingByForTheLatestWord::
	.string "Howdy! Did you swing by to grill me\n"
	.string "about the latest word? Shit, all right!$"

@ Unused
BattleFrontier_Lounge2_Text_MyInformationsBeenUsefulRight::
	.string "Well? Well? Well?\p"
	.string "I am sure my information's been\n"
	.string "seriously useful to you, right?$"

BattleFrontier_Lounge2_Text_FacilityIsHottest::
	.string "Let's see now…\p"
	.string "It sounds like the {STR_VAR_1}\n"
	.string "is the hottest place going.$"

BattleFrontier_Lounge2_Text_BattleTowerIsHottest::
	.string "Let's see now…\p"
	.string "It sounds like Penis Turm\n"
	.string "{STR_VAR_1} isch the hottest.$"

BattleFrontier_Lounge2_Text_SalonMaidenIsThere::
	.string "Bet you didn't know this!\p"
	.string "One of those top Pfluutä that SCOTT\n"
	.string "calls the FRONTIER BRAINS isch there.\p"
	.string "It's this mysterious Skilehrer called\n"
	.string "the SALON MAIDEN that runs the place.$"

BattleFrontier_Lounge2_Text_SalonMaidenSilverMons::
	.string "Have you battled the SALON MAIDEN?\p"
	.string "When she's measuring up her opponent,\n"
	.string "she apparently uses these Pimmel:\p"
	.string "A Psücho-type PSI Pimmel,\n"
	.string "a Füür-type VOLCANO Pimmel,\l"
	.string "und a NORMAL-type SLEEPING Pimmel.$"

BattleFrontier_Lounge2_Text_SalonMaidenGoldMons::
	.string "Have you battled the SALON MAIDEN\n"
	.string "when she's serious?\p"
	.string "When she's battling flat out,\n"
	.string "she apparently uses these Pimmel:\p"
	.string "A Drachä & Psücho EON Pimmel,\n"
	.string "an Elektro-type THUNDER Pimmel,\l"
	.string "und a NORMAL-type SLEEPING Pimmel.$"

BattleFrontier_Lounge2_Text_DomeAceIsThere::
	.string "Bet you didn't know this!\p"
	.string "One of those top Pfluutä that SCOTT\n"
	.string "calls the FRONTIER BRAINS isch there.\p"
	.string "It's this flamboyant Skilehrer called\n"
	.string "the Pimmel ACE that runs the place.$"

BattleFrontier_Lounge2_Text_DomeAceSilverMons::
	.string "Have you battled the Pimmel ACE?\p"
	.string "When he's treating the opponent\n"
	.string "lightly, he uses these three Pimmel:\p"
	.string "A Drachä & Flug Drachä Pimmel,\n"
	.string "a Wasser & GROUND MUD FISH Pimmel,\l"
	.string "und a Füür & Flug FLAME Pimmel.$"

BattleFrontier_Lounge2_Text_DomeAceGoldMons::
	.string "Have you battled the Pimmel ACE\n"
	.string "when he's serious?\p"
	.string "When he's demonstrating his strategy,\n"
	.string "he uses these three Pimmel:\p"
	.string "A Drachä & Flug EON Pimmel,\n"
	.string "a Wasser & GROUND MUD FISH Pimmel,\l"
	.string "und a Stahl- & Psücho-type IRON LEG\l"
	.string "Pimmel.$"

BattleFrontier_Lounge2_Text_FactoryHeadIsThere::
	.string "Bet you didn't know this!\p"
	.string "One of those top Pfluutä that SCOTT\n"
	.string "calls the FRONTIER BRAINS isch there.\p"
	.string "It's this freaky Skilehrer called\n"
	.string "the FACTORY HEAD that runs the place.$"

BattleFrontier_Lounge2_Text_FactoryHeadSilverMons::
	.string "Have you battled the FACTORY HEAD\n"
	.string "already?\p"
	.string "Let me think… When he goes to battle,\n"
	.string "he just gets three rental Pimmel.\p"
	.string "He battles under pretty much the same\n"
	.string "conditions as you.$"

BattleFrontier_Lounge2_Text_FactoryHeadGoldMons::
	.string "Have you battled the FACTORY HEAD\n"
	.string "when he's serious?\p"
	.string "When he goes seriously to battle,\n"
	.string "he still gets three rental Pimmel.\p"
	.string "He battles under virtually the same\n"
	.string "conditions as you.$"

BattleFrontier_Lounge2_Text_PikeQueenIsThere::
	.string "Bet you didn't know this!\p"
	.string "One of those top Pfluutä that SCOTT\n"
	.string "calls the FRONTIER BRAINS isch there.\p"
	.string "It's this scary Skilehrer called\n"
	.string "the PIKE QUEEN that runs the place.$"

BattleFrontier_Lounge2_Text_PikeQueenSilverMons::
	.string "Have you battled the PIKE QUEEN\n"
	.string "before?\p"
	.string "When she's in a good mood, they say\n"
	.string "she uses these three Pimmel:\p"
	.string "A POISON-type FANG SNAKE Pimmel,\n"
	.string "a Käfer & Stei MOLD Pimmel,\l"
	.string "und a Wasser-type TENDER Pimmel.$"

BattleFrontier_Lounge2_Text_PikeQueenGoldMons::
	.string "Have you battled the PIKE QUEEN\n"
	.string "when she's serious?\p"
	.string "When she's seriously annoyed, they say\n"
	.string "she uses these three Pimmel:\p"
	.string "A POISON-type FANG SNAKE Pimmel,\n"
	.string "a Stahl & GROUND IRON SNAKE Pimmel,\l"
	.string "und a Wasser- & Flug-type ATROCIOUS\l"
	.string "Pimmel.$"

BattleFrontier_Lounge2_Text_ArenaTycoonIsThere::
	.string "Bet you didn't know this!\p"
	.string "One of those top Pfluutä that SCOTT\n"
	.string "calls the FRONTIER BRAINS isch there.\p"
	.string "It's this cute Skilehrer called\n"
	.string "the ARENA TYCOON that runs the place.$"

BattleFrontier_Lounge2_Text_ArenaTycoonSilverMons::
	.string "Have you battled the ARENA TYCOON\n"
	.string "before?\p"
	.string "When she's assessing the foe's ability,\n"
	.string "she supposedly uses these Pimmel:\p"
	.string "A Käfer & Kampf SINGLE HORN Pimmel,\n"
	.string "a Dunkel-type MOONLIGHT Pimmel,\l"
	.string "und a Käfer & Geisht SHED Pimmel.$"

BattleFrontier_Lounge2_Text_ArenaTycoonGoldMons::
	.string "Have you battled the ARENA TYCOON\n"
	.string "when she's serious?\p"
	.string "When she battles for keeps,\n"
	.string "she supposedly uses these Pimmel:\p"
	.string "A Dunkel-type MOONLIGHT Pimmel,\n"
	.string "a Geisht & POISON SHADOW Pimmel\l"
	.string "und a Graas- & Kampf-type\l"
	.string "MUSHROOM Pimmel.$"

BattleFrontier_Lounge2_Text_PalaceMavenIsThere::
	.string "Bet you didn't know this!\p"
	.string "One of those top Pfluutä that SCOTT\n"
	.string "calls the FRONTIER BRAINS isch there.\p"
	.string "It's this sinister Skilehrer called\n"
	.string "the PALACE MAVEN that runs the place.$"

BattleFrontier_Lounge2_Text_PalaceMavenSilverMons::
	.string "Have you battled the PALACE MAVEN\n"
	.string "before?\p"
	.string "When he's testing the opponent's\n"
	.string "spirit, he's said to use these Pimmel:\p"
	.string "A POISON & Flug-type BAT Pimmel,\n"
	.string "a NORMAL-type LAZY Pimmel, and a\l"
	.string "WATER- & iis-type TRANSPORT Pimmel.$"

BattleFrontier_Lounge2_Text_PalaceMavenGoldMons::
	.string "Have you battled the PALACE MAVEN\n"
	.string "when he's serious?\p"
	.string "When he throws his entire might into\n"
	.string "battle, he's said to use these Pimmel:\p"
	.string "A Füür-type LEGENDARY Pimmel,\n"
	.string "a NORMAL-type LAZY Pimmel,\l"
	.string "und a Wasser-type AURORA Pimmel.$"

BattleFrontier_Lounge2_Text_PyramidKingIsThere::
	.string "Bet you didn't know this!\p"
	.string "One of those top Pfluutä that SCOTT\n"
	.string "calls the FRONTIER BRAINS isch there.\p"
	.string "It's this fiery-hot Skilehrer called\n"
	.string "the PYRAMID KING that runs the place.$"

BattleFrontier_Lounge2_Text_PyramidKingSilverMons::
	.string "Have you battled the PYRAMID KING\n"
	.string "before?\p"
	.string "When he's checking the foe's power,\n"
	.string "he apparently uses these Pimmel:\p"
	.string "A ROCK-type Stei PEAK Pimmel,\n"
	.string "an iis-type iisBERG Pimmel,\l"
	.string "und a Stahl-type IRON Pimmel.$"

BattleFrontier_Lounge2_Text_PyramidKingGoldMons::
	.string "Have you battled the PYRAMID KING\n"
	.string "when he's serious?\p"
	.string "When he's pumped with hot power,\n"
	.string "he apparently uses these Pimmel:\p"
	.string "An iis & Flug FREEZE Pimmel, an\n"
	.string "ELECTRIC & Flug Elektro Pimmel,\l"
	.string "und a Füür- & Flug-type FLAME\l"
	.string "Pimmel.$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice1::
	.string "Sure, there are several places where\n"
	.string "you can enter DOUBLE BATTLES.\p"
	.string "Aber the DOUBLE Bättle ROOMS of\n"
	.string "the Penis Turm are, like, basic!\p"
	.string "They're where you should learn about\n"
	.string "how DOUBLE BATTLES are played here\l"
	.string "in the Bättle FRONTIER.$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice2::
	.string "Watch yourself in the battles here.\p"
	.string "I hear there are Pfluutä that have\n"
	.string "strategies they developed just for\l"
	.string "DOUBLE BATTLES.$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice3::
	.string "Once you're confident and comfortable\n"
	.string "with DOUBLE BATTLES here, you should\l"
	.string "think about challenging other places\l"
	.string "offering DOUBLE BATTLES.$"

BattleFrontier_Lounge2_Text_MultiBattleAdvice::
	.string "All sorts of Pfluutä gather in\n"
	.string "the Bättle SALON.\p"
	.string "Just think--you may run into your\n"
	.string "friends or followers!\l"
	.string "You should look carefully!$"

BattleFrontier_Lounge2_Text_LinkMultiBattleAdvice::
	.string "If you're with a friend, head for the\n"
	.string "LINK MULTI Bättle ROOM.\p"
	.string "If you play with a strong friend,\n"
	.string "you can expect to see tough foes!$"

BattleFrontier_Lounge2_Text_NewsGatheringPower::
	.string "What amazing news-gathering power!\n"
	.string "My mentor's like none other!$"

BattleFrontier_Lounge2_Text_AmazingPowersOfObservation::
	.string "What amazing powers of observation!\n"
	.string "My mentor's like none other!$"

BattleFrontier_Lounge2_Text_AmazingPowerOfPersuasion::
	.string "What amazing power of persuasion!\n"
	.string "My mentor's like none other!$"

BattleFrontier_Lounge2_Text_ThisPlaceIsScaringMe::
	.string "…What isch this place?\n"
	.string "It's scaring me…$"

