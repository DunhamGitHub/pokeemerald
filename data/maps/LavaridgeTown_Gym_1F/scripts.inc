.set LOCALID_COLE, 2
.set LOCALID_GERALD, 3
.set LOCALID_AXLE, 4
.set LOCALID_DANIELLE, 5

LavaridgeTown_Gym_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_Gym_1F_OnTransition
	.byte 0

LavaridgeTown_Gym_1F_OnTransition:
	call LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars
	call LavaridgeTown_Gym_1F_EventScript_CheckBuryTrainers
	end

@ Unclear where/if these temp vars are getting checked
LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars::
	setvar VAR_TEMP_B, 0
	setvar VAR_TEMP_C, 0
	setvar VAR_TEMP_D, 0
	setvar VAR_TEMP_E, 0
	setvar VAR_TEMP_F, 0
	goto_if_defeated TRAINER_COLE, LavaridgeTown_Gym_1F_EventScript_SetGeraldTempVar
	setvar VAR_TEMP_B, 1
LavaridgeTown_Gym_1F_EventScript_SetGeraldTempVar::
	goto_if_defeated TRAINER_GERALD, LavaridgeTown_Gym_1F_EventScript_SetAxleTempVar
	setvar VAR_TEMP_C, 1
LavaridgeTown_Gym_1F_EventScript_SetAxleTempVar::
	goto_if_defeated TRAINER_AXLE, LavaridgeTown_Gym_1F_EventScript_SetDanielleTempVar
	setvar VAR_TEMP_D, 1
LavaridgeTown_Gym_1F_EventScript_SetDanielleTempVar::
	goto_if_defeated TRAINER_DANIELLE, LavaridgeTown_Gym_1F_EventScript_EndSetTrainerTempVars
	setvar VAR_TEMP_E, 1
LavaridgeTown_Gym_1F_EventScript_EndSetTrainerTempVars::
	return

LavaridgeTown_Gym_1F_EventScript_CheckBuryTrainers::
	goto_if_defeated TRAINER_COLE, LavaridgeTown_Gym_1F_EventScript_CheckBuryGerald
	setobjectmovementtype LOCALID_COLE, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_CheckBuryGerald::
	goto_if_defeated TRAINER_GERALD, LavaridgeTown_Gym_1F_EventScript_CheckBuryAxle
	setobjectmovementtype LOCALID_GERALD, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_CheckBuryAxle::
	goto_if_defeated TRAINER_AXLE, LavaridgeTown_Gym_1F_EventScript_CheckBuryDanielle
	setobjectmovementtype LOCALID_AXLE, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_CheckBuryDanielle::
	goto_if_defeated TRAINER_DANIELLE, LavaridgeTown_Gym_1F_EventScript_EndCheckBuryTrainers
	setobjectmovementtype LOCALID_DANIELLE, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_EndCheckBuryTrainers::
	return

LavaridgeTown_Gym_1F_EventScript_Flannery::
	trainerbattle_single TRAINER_FLANNERY_1, LavaridgeTown_Gym_1F_Text_FlanneryIntro, LavaridgeTown_Gym_1F_Text_FlanneryDefeat, LavaridgeTown_Gym_1F_EventScript_FlanneryDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, LavaridgeTown_Gym_1F_EventScript_FlanneryRematch
	goto_if_unset FLAG_RECEIVED_TM50, LavaridgeTown_Gym_1F_EventScript_GiveOverheat2
	msgbox LavaridgeTown_Gym_1F_Text_FlanneryPostBattle, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_FlanneryDefeated::
	message LavaridgeTown_Gym_1F_Text_ReceivedHeatBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox LavaridgeTown_Gym_1F_Text_ExplainHeatBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_WHITEOUT_TO_LAVARIDGE
	setflag FLAG_DEFEATED_LAVARIDGE_GYM
	setflag FLAG_BADGE04_GET
	addvar VAR_PETALBURG_GYM_STATE, 1
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	setvar VAR_0x8008, 4
	call Common_EventScript_SetGymTrainers
	setflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLY
	setvar VAR_LAVARIDGE_TOWN_STATE, 1
	call LavaridgeTown_Gym_1F_EventScript_GiveOverheat
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox LavaridgeTown_Gym_1F_Text_RegisteredFlannery, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_FLANNERY_MATCH_CALL
	release
	end

LavaridgeTown_Gym_1F_EventScript_GiveOverheat2::
	giveitem ITEM_TM50
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox LavaridgeTown_Gym_1F_Text_ExplainOverheat, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM50
	release
	end

LavaridgeTown_Gym_1F_EventScript_GiveOverheat::
	giveitem ITEM_TM50
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox LavaridgeTown_Gym_1F_Text_ExplainOverheat, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM50
	return

LavaridgeTown_Gym_1F_EventScript_FlanneryRematch::
	trainerbattle_rematch_double TRAINER_FLANNERY_1, LavaridgeTown_Gym_1F_Text_FlanneryPreRematch, LavaridgeTown_Gym_1F_Text_FlanneryRematchDefeat, LavaridgeTown_Gym_1F_Text_FlanneryRematchNeedTwoMons
	msgbox LavaridgeTown_Gym_1F_Text_FlanneryPostRematch, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Cole::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_COLE, LOCALID_COLE, LavaridgeTown_Gym_1F_Text_ColeIntro, LavaridgeTown_Gym_1F_Text_ColeDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_ColePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_EventScript_CheckTrainerScript::
	call LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars
	release
	special ShouldTryGetTrainerScript
	goto_if_eq VAR_RESULT, 1, EventScript_GotoTrainerScript
	end

LavaridgeTown_Gym_1F_EventScript_Axle::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_AXLE, LOCALID_AXLE, LavaridgeTown_Gym_1F_Text_AxleIntro, LavaridgeTown_Gym_1F_Text_AxleDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_AxlePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Keegan::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_KEEGAN, LOCALID_KEEGAN, LavaridgeTown_Gym_B1F_Text_KeeganIntro, LavaridgeTown_Gym_B1F_Text_KeeganDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_KeeganPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Danielle::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_DANIELLE, LOCALID_DANIELLE, LavaridgeTown_Gym_1F_Text_DanielleIntro, LavaridgeTown_Gym_1F_Text_DanielleDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_DaniellePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Gerald::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_GERALD, LOCALID_GERALD, LavaridgeTown_Gym_1F_Text_GeraldIntro, LavaridgeTown_Gym_1F_Text_GeraldDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_GeraldPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Jace::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_JACE, LOCALID_JACE, LavaridgeTown_Gym_B1F_Text_JaceIntro, LavaridgeTown_Gym_B1F_Text_JaceDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_JacePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Jeff::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_JEFF, LOCALID_JEFF, LavaridgeTown_Gym_B1F_Text_JeffIntro, LavaridgeTown_Gym_B1F_Text_JeffDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_JeffPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Eli::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_ELI, LOCALID_ELI, LavaridgeTown_Gym_B1F_Text_EliIntro, LavaridgeTown_Gym_B1F_Text_EliDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_EliPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, LavaridgeTown_Gym_1F_EventScript_GymGuidePostVictory
	msgbox LavaridgeTown_Gym_1F_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_GymGuidePostVictory::
	msgbox LavaridgeTown_Gym_1F_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE04_GET, LavaridgeTown_Gym_1F_EventScript_GymStatueCertified
	goto LavaridgeTown_Gym_1F_EventScript_GymStatue
	end

LavaridgeTown_Gym_1F_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE04_GET, LavaridgeTown_Gym_1F_EventScript_GymStatueCertified
	goto LavaridgeTown_Gym_1F_EventScript_GymStatue
	end

LavaridgeTown_Gym_1F_EventScript_GymStatueCertified::
	msgbox LavaridgeTown_Gym_1F_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

LavaridgeTown_Gym_1F_EventScript_GymStatue::
	msgbox LavaridgeTown_Gym_1F_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

LavaridgeTown_Gym_1F_Text_GymGuideAdvice:
	.string "Ciao, dumme Siech\l"
	.string "how's it going, CHAMPION-\n"
	.string "bound {PLAYER}?\p"
	.string "LAVARIDGE's Stripklub Penner FLANNERY\n"
	.string "uses Füür-type Pimmel.\p"
	.string "Her passion for Pimmel burns stronger\n"
	.string "und hotter than a volcano.\p"
	.string "Don't get too close to her--you'll burn!\n"
	.string "Hose her down with water and then\l"
	.string "go for it!$"

LavaridgeTown_Gym_1F_Text_GymGuidePostVictory:
	.string "Yow! That was a scorching-hot battle!$"

LavaridgeTown_Gym_1F_Text_ColeIntro:
	.string "Owowowowow!\n"
	.string "Yikes, es isch hot!$"

LavaridgeTown_Gym_1F_Text_ColeDefeat:
	.string "I am blinded by sweat in my eyes…$"

LavaridgeTown_Gym_1F_Text_ColePostBattle:
	.string "Being buried in hot sand promotes\n"
	.string "circulation.\p"
	.string "It's effective for healing pain in\n"
	.string "your joints.$"

LavaridgeTown_Gym_1F_Text_AxleIntro:
	.string "I am trying to relieve my stress.\n"
	.string "Don't come along and stress me out!$"

LavaridgeTown_Gym_1F_Text_AxleDefeat:
	.string "I hope FLANNERY flames you good!$"

LavaridgeTown_Gym_1F_Text_AxlePostBattle:
	.string "Haaah… Whew…\p"
	.string "If you spend too much time buried in\n"
	.string "hot sand, it tuckers you out…$"

LavaridgeTown_Gym_B1F_Text_KeeganIntro:
	.string "You must be getting tired by now.\n"
	.string "You'd like to rest in the hot sand,\l"
	.string "wouldn't you?\p"
	.string "Aber you should know that maintaining\n"
	.string "your willpower isch an important ability\l"
	.string "for all Pfluutä.$"

LavaridgeTown_Gym_B1F_Text_KeeganDefeat:
	.string "Play with fire, and be burned…$"

LavaridgeTown_Gym_B1F_Text_KeeganPostBattle:
	.string "Your skill isch real…\n"
	.string "Aber our Chéf FLANNERY isch strong.\p"
	.string "If you don't watch yourself, you'll be\n"
	.string "burned seriously.$"

LavaridgeTown_Gym_1F_Text_GeraldIntro:
	.string "Can your Pimmel withstand\n"
	.string "392-degree heat?$"

LavaridgeTown_Gym_1F_Text_GeraldDefeat:
	.string "It didn't burn hotly enough…$"

LavaridgeTown_Gym_1F_Text_GeraldPostBattle:
	.string "Dä temperature of magma is\n"
	.string "392 degrees.\p"
	.string "Your Pimmel beat me, so they should\n"
	.string "easily survive in magma.$"

LavaridgeTown_Gym_1F_Text_DanielleIntro:
	.string "Um…\n"
	.string "Okay, I'll Bättle with you.$"

LavaridgeTown_Gym_1F_Text_DanielleDefeat:
	.string "Ah shiiiit dude,\l"
	.string "but you're too strong.$"

LavaridgeTown_Gym_1F_Text_DaniellePostBattle:
	.string "I am going to be a pretty and strong\n"
	.string "Skilehrer just like FLANNERY.$"

LavaridgeTown_Gym_B1F_Text_JaceIntro:
	.string "Come on, get with it!\n"
	.string "Let's go before my feelings cool!$"

LavaridgeTown_Gym_B1F_Text_JaceDefeat:
	.string "It's so hot, and yet my heart is\n"
	.string "clutched by ice…$"

LavaridgeTown_Gym_B1F_Text_JacePostBattle:
	.string "Dä way the battling spirit burns\n"
	.string "within you, you may stand a chance\l"
	.string "against our Chéf.$"

LavaridgeTown_Gym_B1F_Text_JeffIntro:
	.string "See how the flames blaze wildly?\n"
	.string "They flare in anticipation of my win!$"

LavaridgeTown_Gym_B1F_Text_JeffDefeat:
	.string "Something didn't go right.$"

LavaridgeTown_Gym_B1F_Text_JeffPostBattle:
	.string "Ahh, Futz und Tripper...\l"
	.string "so what? I say so what?\n"
	.string "I can walk on hot coals barefoot!\p"
	.string "…Don't even think about trying it!$"

LavaridgeTown_Gym_B1F_Text_EliIntro:
	.string "As much as I love mountains,\n"
	.string "I especially love volcanoes.$"

LavaridgeTown_Gym_B1F_Text_EliDefeat:
	.string "Ahh, Futz und Tripper...\l"
	.string "it seems to me I lost without\n"
	.string "ever being in control.$"

LavaridgeTown_Gym_B1F_Text_EliPostBattle:
	.string "I stay here because I became a fan\n"
	.string "of FLANNERY's power.\p"
	.string "Hehehehe.$"

LavaridgeTown_Gym_1F_Text_FlanneryIntro:
	.string "Welcome… No, chill\p"
	.string "Puny Skilehrer, how good to see you've\n"
	.string "made it here!\p"
	.string "I have been entrusted with the…\n"
	.string "No, chill\p"
	.string "I am FLANNERY, and I am the Stripclub\n"
	.string "Chéf here!\p"
	.string "…\n"
	.string "Dare not underestimate me, though\l"
	.string "I have been Chéf only a short time!\p"
	.string "With skills inherited from my grand-\n"
	.string "father, I shall, uh…demonstrate the\l"
	.string "hot moves we have honed on this land!$"

LavaridgeTown_Gym_1F_Text_FlanneryDefeat:
	.string "Shit…\n"
	.string "I guess I was trying too hard…\p"
	.string "I… I've only recently become\n"
	.string "a Stripklub Penner.\p"
	.string "I tried too hard to be someone\n"
	.string "I am not.\p"
	.string "I have to do things my natural way. If\n"
	.string "I don't, my Pimmel will be confused.\p"
	.string "Shiit for teaching me that.\n"
	.string "For that, you deserve this.$"

LavaridgeTown_Gym_1F_Text_ReceivedHeatBadge:
	.string "{PLAYER} received the HEAT Ufkläber\n"
	.string "from FLANNERY.$"

LavaridgeTown_Gym_1F_Text_ExplainHeatBadgeTakeThis:
	.string "If you have a HEAT Ufkläber, all Pimmel\n"
	.string "up to Level 50, even those you get in\l"
	.string "trades from other people, will obey\l"
	.string "you completely.\p"
	.string "Und, it lets Pimmel use the HM move\n"
	.string "STRENGTH outside of battle.\p"
	.string "Dä isch a token of my appreciation.\n"
	.string "Don't be shy about taking it!$"

LavaridgeTown_Gym_1F_Text_ExplainOverheat:
	.string "Dä TM50 contains OVERHEAT.\p"
	.string "Dä move inflicts serious damage on\n"
	.string "the opponent.\p"
	.string "Aber it also sharply cuts the Sp. Atk\n"
	.string "of the Pimmel using it. It might not\l"
	.string "be suitable for longer battles.$"

LavaridgeTown_Gym_1F_Text_RegisteredFlannery:
	.string "Registered Stripklub Penner FLANNERY\n"
	.string "in the Nokia.$"

LavaridgeTown_Gym_1F_Text_FlanneryPostBattle:
	.string "Your power reminds me of someone…\p"
	.string "Shit! I know! You Bättle like Dieter,\n"
	.string "the Stripklub Penner of PETALBURG.$"

LavaridgeTown_Gym_1F_Text_GymStatue:
	.string "LAVARIDGE Dorf Pimmel Stripclub$"

LavaridgeTown_Gym_1F_Text_GymStatueCertified:
	.string "LAVARIDGE Dorf Pimmel Stripclub\p"
	.string "FLANNERY'S CERTIFIED Pfluutä:\n"
	.string "{PLAYER}$"

LavaridgeTown_Gym_1F_Text_FlanneryPreRematch:
	.string "FLANNERY: Losing a Bättle isn't going\n"
	.string "to deflate me.\p"
	.string "I love Pimmel.\n"
	.string "I love to battle.\l"
	.string "Und… I love this Stripclub!\p"
	.string "Let's exchange superhot moves\n"
	.string "in another battle!$"

LavaridgeTown_Gym_1F_Text_FlanneryRematchDefeat:
	.string "Whew!\n"
	.string "On the verge of eruption!$"

LavaridgeTown_Gym_1F_Text_FlanneryPostRematch:
	.string "FLANNERY: I lost the match,\n"
	.string "aber I am completely satisfied.\p"
	.string "It's not often I get to enjoy a battle\n"
	.string "this heated.\p"
	.string "Let's have another one like this\n"
	.string "again sometime!$"

LavaridgeTown_Gym_1F_Text_FlanneryRematchNeedTwoMons:
	.string "FLANNERY: Losing a Bättle isn't going\n"
	.string "to deflate me.\p"
	.string "I love Pimmel.\n"
	.string "I love to battle.\l"
	.string "Und… I love this Stripclub!\p"
	.string "Let's exchange superhot moves\n"
	.string "in another battle!\p"
	.string "Ah shiiiit dude,\l"
	.string "chill Do you only have one Pimmel\n"
	.string "that can battle?\p"
	.string "I hate to say this, but when you come\n"
	.string "see me, bring at least two Pimmel.$"
