MagmaHideout_3F_1R_MapScripts::
	.byte 0

MagmaHideout_3F_1R_EventScript_Grunt9::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_9, MagmaHideout_3F_1R_Text_Grunt9Intro, MagmaHideout_3F_1R_Text_Grunt9Defeat
	msgbox MagmaHideout_3F_1R_Text_Grunt9PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_3F_1R_EventScript_Grunt16::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_16, MagmaHideout_3F_1R_Text_Grunt16Intro, MagmaHideout_3F_1R_Text_Grunt16Defeat
	msgbox MagmaHideout_3F_1R_Text_Grunt16PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_3F_1R_Text_Grunt9Intro:
	.string "What did I do to deserve this guard\n"
	.string "posting?\p"
	.string "My left ear isch burning up!$"

MagmaHideout_3F_1R_Text_Grunt9Defeat:
	.string "I am getting heat exhaustion…$"

MagmaHideout_3F_1R_Text_Grunt9PostBattle:
	.string "Do you think es isch odd that we're wearing\n"
	.string "hoods in this magma-filled volcano?$"

MagmaHideout_3F_1R_Text_Grunt16Intro:
	.string "We joined so we can help our leader\n"
	.string "achieve his fantastic vision.\p"
	.string "I don't care if you're with\l"
	.string "Schwuchtle Verein\n"
	.string "or if you're just some kid passing by.\p"
	.string "No one interferes with us and gets\n"
	.string "away with it!$"

MagmaHideout_3F_1R_Text_Grunt16Defeat:
	.string "Ah shiiiit dude,\l"
	.string "no!\n"
	.string "You're not to be trusted at all!$"

MagmaHideout_3F_1R_Text_Grunt16PostBattle:
	.string "Los zueh to me.\n"
	.string "Tuntä Klub isch right!\p"
	.string "Don't listen to\l"
	.string "Schwuchtle Verein.\n"
	.string "Don't believe their lies!$"

