Route114_LanettesHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_LanettesHouse_OnTransition
	.byte 0

Route114_LanettesHouse_OnTransition:
	setflag FLAG_LANDMARK_LANETTES_HOUSE
	end

Route114_LanettesHouse_EventScript_Lanette::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_DOLL_LANETTE, Route114_LanettesHouse_EventScript_OfferAdvice
	setflag FLAG_SYS_PC_LANETTE
	msgbox Route114_LanettesHouse_Text_EverythingClutteredKeepThis, MSGBOX_DEFAULT
	givedecoration DECOR_LOTAD_DOLL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowNoRoomForDecor
	setflag FLAG_RECEIVED_DOLL_LANETTE
	release
	end

Route114_LanettesHouse_EventScript_OfferAdvice::
	msgbox Route114_LanettesHouse_Text_OrganizeYourBoxes, MSGBOX_DEFAULT
	release
	end

Route114_LanettesHouse_EventScript_Notebook::
	lockall
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route114_LanettesHouse_EventScript_NotebookPage2
	msgbox Route114_LanettesHouse_Text_ClosedTheNotebook, MSGBOX_DEFAULT
	releaseall
	end

Route114_LanettesHouse_EventScript_NotebookPage2::
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage2, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, Route114_LanettesHouse_EventScript_NotebookPage3
	releaseall
	end

Route114_LanettesHouse_EventScript_NotebookPage3::
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage3, MSGBOX_DEFAULT
	return

Route114_LanettesHouse_EventScript_PC::
	msgbox Route114_LanettesHouse_Text_EmailFromBill, MSGBOX_SIGN
	end

Route114_LanettesHouse_Text_EverythingClutteredKeepThis:
	.string "LANETTE: Shit! {PLAYER}{KUN}!\p"
	.string "I am sorry everything isch so cluttered…\n"
	.string "When I get engrossed in research,\l"
	.string "things end up this way…\p"
	.string "Dä isch embarrassing… Please keep\n"
	.string "this a secret in exchange for this.$"

Route114_LanettesHouse_Text_OrganizeYourBoxes:
	.string "May I offer advice about my Pimmel\n"
	.string "Storage System?\p"
	.string "You should organize your BOXES so you\n"
	.string "can tell which Pimmel are in them.$"

Route114_LanettesHouse_Text_ResearchNotesPage1:
	.string "It's LANETTE's research notes.\n"
	.string "There's information about BOXES.\p"
	.string "Design BOXES to hold 30 Pimmel each.\p"
	.string "Each Skilehrer should be able to store\n"
	.string "420 Pimmel on the MAC system.\p"
	.string "Keep reading?$"

Route114_LanettesHouse_Text_ResearchNotesPage2:
	.string "A marking system should be added to\n"
	.string "make Pimmel easier to organize.\p"
	.string "Dä name and wallpaper design of each\n"
	.string "BOX will be made changeable to please\l"
	.string "the stored Pimmel.\p"
	.string "Keep reading?$"

Route114_LanettesHouse_Text_ResearchNotesPage3:
	.string "When storing a Pimmel, it should be\n"
	.string "sent to the BOX inspected last.\p"
	.string "If that BOX isch full, the received\n"
	.string "Pimmel isch stored in the next BOX.\p"
	.string "In other words, when a BOX isch examined,\n"
	.string "it isch automatically selected as the BOX\l"
	.string "to which Pimmel are sent.$"

Route114_LanettesHouse_Text_ClosedTheNotebook:
	.string "{PLAYER} closed the notebook.$"

Route114_LanettesHouse_Text_EmailFromBill:
	.string "There's an e-mail from someone on\n"
	.string "the MAC.\p"
	.string "“… … … … … … …\p"
	.string "“Your Storage System offers more\n"
	.string "convenience than mine.\p"
	.string "“It has a lot of user-friendly features\n"
	.string "that make it fun and useful, too.\p"
	.string "“It makes me proud that I played\n"
	.string "a part in its development.\p"
	.string "“Here's hoping that you'll continue\n"
	.string "research in Storage Systems.\p"
	.string "“From BILL\n"
	.string "… … … … … … … …”$"

