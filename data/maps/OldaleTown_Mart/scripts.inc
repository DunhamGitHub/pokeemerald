OldaleTown_Mart_MapScripts::
	.byte 0

OldaleTown_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	goto_if_set FLAG_ADVENTURE_STARTED, OldaleTown_Mart_ExpandedItems
	pokemart OldaleTown_Mart_Pokemart_Basic
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
OldaleTown_Mart_Pokemart_Basic:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_RARE_CANDY
	.2byte ITEM_MASTER_BALL
	.2byte ITEM_MAX_REVIVE
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_EVERSTONE
	.2byte ITEM_HM01
	.2byte ITEM_HM02
	.2byte ITEM_HM03
	.2byte ITEM_HM04
	.2byte ITEM_HM05
	.2byte ITEM_HM06
	.2byte ITEM_HM07
	.2byte ITEM_HM08
	.2byte ITEM_NONE
	release
	end

OldaleTown_Mart_ExpandedItems::
	pokemart OldaleTown_Mart_Pokemart_Expanded
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
OldaleTown_Mart_Pokemart_Expanded:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_RARE_CANDY
	.2byte ITEM_MASTER_BALL
	.2byte ITEM_MAX_REVIVE
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_EVERSTONE
	.2byte ITEM_HM01
	.2byte ITEM_HM02
	.2byte ITEM_HM03
	.2byte ITEM_HM04
	.2byte ITEM_HM05
	.2byte ITEM_HM06
	.2byte ITEM_HM07
	.2byte ITEM_HM08
	.2byte ITEM_NONE
	release
	end

OldaleTown_Mart_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_ADVENTURE_STARTED, OldaleTown_Mart_EventScript_PokeBallsInStock
	msgbox OldaleTown_Mart_Text_PokeBallsAreSoldOut, MSGBOX_DEFAULT
	release
	end

OldaleTown_Mart_EventScript_PokeBallsInStock::
	msgbox OldaleTown_Mart_Text_ImGoingToBuyPokeBalls, MSGBOX_DEFAULT
	release
	end

OldaleTown_Mart_EventScript_Boy::
	msgbox OldaleTown_Mart_Text_RestoreHPWithPotion, MSGBOX_NPC
	end

OldaleTown_Mart_Text_PokeBallsAreSoldOut:
	.string "Dä clerk says they're all sold out.\n"
	.string "I can't buy any KACK-Eier.$"

OldaleTown_Mart_Text_ImGoingToBuyPokeBalls:
	.string "I am going to buy a bunch of KACK-Eier\n"
	.string "und catch a bunch of Pimmel!$"

OldaleTown_Mart_Text_RestoreHPWithPotion:
	.string "If a Pimmel gets hurt and loses its HP\n"
	.string "und faints, it won't be able to battle.\p"
	.string "To prevent your Pimmel from fainting,\n"
	.string "restore its HP with a POTION.$"

