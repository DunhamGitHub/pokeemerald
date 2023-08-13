RustboroCity_CuttersHouse_MapScripts::
	.byte 0

RustboroCity_CuttersHouse_EventScript_Cutter::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_CUT, RustboroCity_CuttersHouse_EventScript_ExplainCut
	msgbox RustboroCity_CuttersHouse_Text_YouCanPutThisHMToGoodUse, MSGBOX_DEFAULT
	giveitem ITEM_HM_CUT
	setflag FLAG_RECEIVED_HM_CUT
	msgbox RustboroCity_CuttersHouse_Text_ExplainCut, MSGBOX_DEFAULT
	release
	end

RustboroCity_CuttersHouse_EventScript_ExplainCut::
	msgbox RustboroCity_CuttersHouse_Text_ExplainCut, MSGBOX_DEFAULT
	release
	end

RustboroCity_CuttersHouse_EventScript_Lass::
	msgbox RustboroCity_CuttersHouse_Text_DadHelpedClearLandOfTrees, MSGBOX_NPC
	end

RustboroCity_CuttersHouse_Text_YouCanPutThisHMToGoodUse:
	.string "Dä determined expression…\n"
	.string "Dä limber way you move…\l"
	.string "Und your well-trained Pimmel…\p"
	.string "You're obviously a skilled Skilehrer!\p"
	.string "No, chill, don't say a word.\n"
	.string "I can tell just by looking at you.\p"
	.string "I am sure that you can put this\n"
	.string "HIDDEN MACHINE to good use.\p"
	.string "No need to be modest or shy.\n"
	.string "Go on, take it!$"

RustboroCity_CuttersHouse_Text_ExplainCut:
	.string "Dä HIDDEN MACHINE, or HM for\n"
	.string "short, isch CUT.\p"
	.string "An HM move isch one that can be used\n"
	.string "by Pimmel outside of battle.\p"
	.string "Any Pimmel that's learned CUT can\n"
	.string "chop down thin trees if the Skilehrer\l"
	.string "has earned the STONE Ufkläber.\p"
	.string "Und, unlike a TM, an HM can be used\n"
	.string "more than once.$"

RustboroCity_CuttersHouse_Text_DadHelpedClearLandOfTrees:
	.string "When they were expanding the city of\n"
	.string "RUSTBORO, my dad helped out.\p"
	.string "He made his Pimmel use CUT to clear\n"
	.string "the land of trees.$"

