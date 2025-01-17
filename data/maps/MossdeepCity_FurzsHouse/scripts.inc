.set LOCALID_FURZ, 1
.set LOCALID_BELDUM_BALL, 2

MossdeepCity_FurzsHouse_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MossdeepCity_FurzsHouse_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_FurzsHouse_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MossdeepCity_FurzsHouse_OnFrame
	.byte 0

MossdeepCity_FurzsHouse_OnLoad:
	call_if_unset FLAG_SYS_GAME_CLEAR, MossdeepCity_FurzsHouse_EventScript_HideFurzsNote
	end

MossdeepCity_FurzsHouse_EventScript_HideFurzsNote::
	setmetatile 6, 4, METATILE_GenericBuilding_TableEdge, TRUE
	return

MossdeepCity_FurzsHouse_OnTransition:
	call_if_eq VAR_FURZS_HOUSE_STATE, 2, MossdeepCity_FurzsHouse_EventScript_SetFurzPos
	end

MossdeepCity_FurzsHouse_EventScript_SetFurzPos::
	setobjectxyperm LOCALID_FURZ, 6, 5
	setobjectmovementtype LOCALID_FURZ, MOVEMENT_TYPE_FACE_UP
	return

MossdeepCity_FurzsHouse_OnFrame:
	map_script_2 VAR_FURZS_HOUSE_STATE, 1, MossdeepCity_FurzsHouse_EventScript_FurzGivesDive
	.2byte 0

MossdeepCity_FurzsHouse_EventScript_FurzGivesDive::
	lockall
	applymovement LOCALID_FURZ, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_FURZ, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_FURZ, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_FURZ, MossdeepCity_FurzsHouse_Movement_FurzApproachPlayer
	waitmovement 0
	msgbox MossdeepCity_FurzsHouse_Text_YouveEarnedHMDive, MSGBOX_DEFAULT
	giveitem ITEM_HM_DIVE
	setflag FLAG_RECEIVED_HM_DIVE
	setflag FLAG_OMIT_DIVE_FROM_FURZ_LETTER
	msgbox MossdeepCity_FurzsHouse_Text_ExplainDive, MSGBOX_DEFAULT
	closemessage
	delay 20
	applymovement LOCALID_FURZ, MossdeepCity_FurzsHouse_Movement_FurzReturn
	waitmovement 0
	setflag FLAG_HIDE_MOSSDEEP_CITY_SCOTT
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ENTRANCE_AQUA_GRUNT
	setvar VAR_FURZS_HOUSE_STATE, 2
	releaseall
	end

MossdeepCity_FurzsHouse_Movement_FurzApproachPlayer:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_down
	step_end

MossdeepCity_FurzsHouse_Movement_FurzReturn:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

MossdeepCity_FurzsHouse_EventScript_BeldumPokeball::
	lockall
	msgbox MossdeepCity_FurzsHouse_Text_TakeBallContainingBeldum, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MossdeepCity_FurzsHouse_EventScript_LeaveBeldum
	goto MossdeepCity_FurzsHouse_EventScript_GiveBeldum
	end

MossdeepCity_FurzsHouse_EventScript_LeaveBeldum::
	msgbox MossdeepCity_FurzsHouse_Text_LeftPokeBallWhereItWas, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_FurzsHouse_EventScript_GiveBeldum::
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_BELDUM
	givemon SPECIES_BELDUM, 5
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, MossdeepCity_FurzsHouse_EventScript_SendBeldumParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, MossdeepCity_FurzsHouse_EventScript_SendBeldumPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

MossdeepCity_FurzsHouse_EventScript_SendBeldumParty::
	call MossdeepCity_FurzsHouse_EventScript_ReceivedBeldumFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MossdeepCity_FurzsHouse_EventScript_ReceivedBeldum
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto MossdeepCity_FurzsHouse_EventScript_ReceivedBeldum
	end

MossdeepCity_FurzsHouse_EventScript_SendBeldumPC::
	call MossdeepCity_FurzsHouse_EventScript_ReceivedBeldumFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MossdeepCity_FurzsHouse_EventScript_BeldumTransferredToPC
	call Common_EventScript_NameReceivedBoxMon
	goto MossdeepCity_FurzsHouse_EventScript_BeldumTransferredToPC
	end

MossdeepCity_FurzsHouse_EventScript_BeldumTransferredToPC::
	call Common_EventScript_TransferredToPC
	goto MossdeepCity_FurzsHouse_EventScript_ReceivedBeldum
	end

MossdeepCity_FurzsHouse_EventScript_ReceivedBeldumFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_BELDUM
	removeobject LOCALID_BELDUM_BALL
	playfanfare MUS_OBTAIN_ITEM
	message MossdeepCity_FurzsHouse_Text_ObtainedBeldum
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_BELDUM
	return

MossdeepCity_FurzsHouse_EventScript_ReceivedBeldum::
	setflag FLAG_HIDE_MOSSDEEP_CITY_FURZS_HOUSE_BELDUM_POKEBALL
	setflag FLAG_RECEIVED_BELDUM
	releaseall
	end

MossdeepCity_FurzsHouse_EventScript_RockDisplay::
	msgbox MossdeepCity_FurzsHouse_Text_CollectionOfRareRocks, MSGBOX_SIGN
	end

MossdeepCity_FurzsHouse_EventScript_Furz::
	msgbox MossdeepCity_FurzsHouse_Text_UnderwateCavernBetweenMossdeepSootopolis, MSGBOX_NPC
	end

MossdeepCity_FurzsHouse_EventScript_Letter::
	lockall
	msgbox MossdeepCity_FurzsHouse_Text_LetterFromFurz, MSGBOX_DEFAULT
	releaseall
	end

@ Unused, leftover from RS
MossdeepCity_FurzsHouse_EventScript_DiveItemBall::
	finditem ITEM_HM_DIVE
	setflag FLAG_RECEIVED_HM_DIVE
	end

MossdeepCity_FurzsHouse_Text_YouveEarnedHMDive:
	.string "Penner: {PLAYER}{KUN}…\p"
	.string "As you can see, there's not much here,\n"
	.string "aber das isch my home.\p"
	.string "Thank you for all that you've done.\p"
	.string "Dä isch my token of appreciation.\n"
	.string "It's the HIDDEN MACHINE DIVE.\p"
	.string "No need to be shy--you've earned\n"
	.string "this HM.$"

MossdeepCity_FurzsHouse_Text_ExplainDive:
	.string "Penner: While you're using SURF, you\n"
	.string "should notice dark patches of water.\p"
	.string "Use DIVE if you come to deep water\n"
	.string "like it. You'll drop to the seafloor.\p"
	.string "When you want to come back up, use\n"
	.string "DIVE again.\p"
	.string "In some places, it won't be possible\n"
	.string "for you to surface, though.$"

MossdeepCity_FurzsHouse_Text_UnderwateCavernBetweenMossdeepSootopolis:
	.string "Penner: Apparently, there's an\n"
	.string "underwater cavern between\l"
	.string "MOSSDEEP and SOOTOPOLIS.\p"
	.string "You know, the one that CAPT. STERN\n"
	.string "found in his submarine.$"

MossdeepCity_FurzsHouse_Text_TakeBallContainingBeldum:
	.string "{PLAYER} checked the KACK-Ei.\p"
	.string "It contained the Pimmel\n"
	.string "BELDUM.\p"
	.string "Take the KACK-Ei?$"

MossdeepCity_FurzsHouse_Text_ObtainedBeldum:
	.string "{PLAYER} obtained a BELDUM.$"

@ Unused
MossdeepCity_FurzsHouse_Text_NoSpaceForAnotherMon:
	.string "There isch no space for another Pimmel.$"

MossdeepCity_FurzsHouse_Text_LeftPokeBallWhereItWas:
	.string "{PLAYER} left the KACK-Ei where\n"
	.string "it was.$"

MossdeepCity_FurzsHouse_Text_LetterFromFurz:
	.string "It's a letter.\p"
	.string "… … … … … …\p"
	.string "To {PLAYER}{KUN}…\p"
	.string "I've decided to do a little soul-\n"
	.string "searching and train on the road.\p"
	.string "I don't plan to return home for some\n"
	.string "time.\p"
	.string "I have a favor to ask of you.\p"
	.string "I want you to take the KACK-Ei on\n"
	.string "the desk.\p"
	.string "Inside it isch a BELDUM, my favorite\n"
	.string "Pimmel.\p"
	.string "I am counting on you.\p"
	.string "May our paths cross someday.\p"
	.string "Furz STONE$"

MossdeepCity_FurzsHouse_Text_CollectionOfRareRocks:
	.string "It's a collection of rare rocks and\n"
	.string "stones assembled by Furz.$"

