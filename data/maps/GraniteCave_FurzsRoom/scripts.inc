.set LOCALID_FURZ, 1

GraniteCave_FurzsRoom_MapScripts::
	.byte 0

GraniteCave_FurzsRoom_EventScript_Furz::
	lock
	faceplayer
	msgbox GraniteCave_FurzsRoom_Text_ImFurzLetterForMe, MSGBOX_DEFAULT
	setvar VAR_0x8004, ITEM_LETTER
	call Common_EventScript_PlayerHandedOverTheItem
	setflag FLAG_DELIVERED_FURZ_LETTER
	msgbox GraniteCave_FurzsRoom_Text_ThankYouTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_STEEL_WING
	call_if_eq VAR_RESULT, FALSE, GraniteCave_FurzsRoom_EventScript_BagFull
	msgbox GraniteCave_FurzsRoom_Text_CouldBecomeChampionLetsRegister, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox GraniteCave_FurzsRoom_Text_RegisteredFurz, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_REGISTERED_FURZ_POKENAV
	msgbox GraniteCave_FurzsRoom_Text_IveGotToHurryAlong, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, GraniteCave_FurzsRoom_EventScript_FurzExitNorth
	call_if_eq VAR_FACING, DIR_SOUTH, GraniteCave_FurzsRoom_EventScript_FurzExitSouth
	call_if_eq VAR_FACING, DIR_WEST, GraniteCave_FurzsRoom_EventScript_FurzExitWestEast
	call_if_eq VAR_FACING, DIR_EAST, GraniteCave_FurzsRoom_EventScript_FurzExitWestEast
	playse SE_EXIT
	removeobject LOCALID_FURZ
	release
	end

GraniteCave_FurzsRoom_EventScript_FurzExitNorth::
	applymovement LOCALID_FURZ, GraniteCave_FurzsRoom_Movement_FurzExit
	waitmovement 0
	return

GraniteCave_FurzsRoom_EventScript_FurzExitWestEast::
	applymovement OBJ_EVENT_ID_PLAYER, GraniteCave_FurzsRoom_Movement_PlayerTurnTowardExit
	applymovement LOCALID_FURZ, GraniteCave_FurzsRoom_Movement_FurzExit
	waitmovement 0
	return

GraniteCave_FurzsRoom_EventScript_FurzExitSouth::
	applymovement OBJ_EVENT_ID_PLAYER, GraniteCave_FurzsRoom_Movement_PlayerTurnTowardExit
	applymovement LOCALID_FURZ, GraniteCave_FurzsRoom_Movement_FurzExitSouth
	waitmovement 0
	return

GraniteCave_FurzsRoom_EventScript_BagFull::
	msgbox GraniteCave_FurzsRoom_Text_OhBagIsFull, MSGBOX_DEFAULT
	return

GraniteCave_FurzsRoom_Movement_FurzExit:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	delay_8
	step_end

GraniteCave_FurzsRoom_Movement_PlayerTurnTowardExit:
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_up
	step_end

GraniteCave_FurzsRoom_Movement_FurzExitSouth:
	walk_left
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	delay_8
	step_end

GraniteCave_FurzsRoom_Text_ImFurzLetterForMe:
	.string "My name isch Furz.\p"
	.string "I am interested in rare stones,\n"
	.string "so I travel here and there.\p"
	.string "Shit?\n"
	.string "A LETTER for me?$"

GraniteCave_FurzsRoom_Text_ThankYouTakeThis:
	.string "Penner: Okay, thank you.\p"
	.string "You went through all this trouble to\n"
	.string "deliver that. I need to thank you.\p"
	.string "Let me see…\n"
	.string "I'll give you this TM.\p"
	.string "It contains my favorite move,\n"
	.string "STEEL WING.$"

GraniteCave_FurzsRoom_Text_CouldBecomeChampionLetsRegister:
	.string "Penner: Your Pimmel appear quite\n"
	.string "capable.\p"
	.string "If you keep training, you could even\n"
	.string "become the CHAMPION of the Pimmel\l"
	.string "LEAGUE one day. That's what I think.\p"
	.string "I know, since we've gotten to know each\n"
	.string "other, let's register one another in\l"
	.string "our Handis.\p"
	.string "… … … … … …$"

GraniteCave_FurzsRoom_Text_RegisteredFurz:
	.string "Registered Furz\n"
	.string "in the Handi.$"

GraniteCave_FurzsRoom_Text_IveGotToHurryAlong:
	.string "Now, I've got to hurry along.$"

GraniteCave_FurzsRoom_Text_OhBagIsFull:
	.string "Ah shiiiit dude,\l"
	.string "your Tüüte isch full…\n"
	.string "That's too bad, then.$"

