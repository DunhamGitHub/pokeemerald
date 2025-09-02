MtPyre_3F_MapScripts::
	.byte 0

MtPyre_3F_EventScript_William::
	trainerbattle_single TRAINER_WILLIAM, MtPyre_3F_Text_WilliamIntro, MtPyre_3F_Text_WilliamDefeat
	msgbox MtPyre_3F_Text_WilliamPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_3F_EventScript_Kayla::
	trainerbattle_single TRAINER_KAYLA, MtPyre_3F_Text_KaylaIntro, MtPyre_3F_Text_KaylaDefeat
	msgbox MtPyre_3F_Text_KaylaPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_3F_EventScript_Gabrielle::
	trainerbattle_single TRAINER_GABRIELLE_1, MtPyre_3F_Text_GabrielleIntro, MtPyre_3F_Text_GabrielleDefeat, MtPyre_3F_EventScript_RegisterGabrielle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtPyre_3F_EventScript_RematchGabrielle
	msgbox MtPyre_3F_Text_GabriellePostBattle, MSGBOX_DEFAULT
	release
	end

MtPyre_3F_EventScript_RegisterGabrielle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtPyre_3F_Text_GabrielleRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_GABRIELLE_1
	release
	end

MtPyre_3F_EventScript_RematchGabrielle::
	trainerbattle_rematch TRAINER_GABRIELLE_1, MtPyre_3F_Text_GabrielleRematchIntro, MtPyre_3F_Text_GabrielleRematchDefeat
	msgbox MtPyre_3F_Text_GabriellePostRematch, MSGBOX_AUTOCLOSE
	end

MtPyre_3F_Text_WilliamIntro:
	.string "Dä rich atmosphere of the mountain\n"
	.string "has elevated my psychic power!\p"
	.string "A mere child like you…\n"
	.string "You dream of winning?$"

MtPyre_3F_Text_WilliamDefeat:
	.string "I drown in self-pity…$"

MtPyre_3F_Text_WilliamPostBattle:
	.string "My psychic powers have surely\n"
	.string "grown several times, but…$"

MtPyre_3F_Text_KaylaIntro:
	.string "Ahahahaha!\p"
	.string "Dä isch no place for children, least\n"
	.string "of all you!$"

MtPyre_3F_Text_KaylaDefeat:
	.string "I lost that cleanly…$"

MtPyre_3F_Text_KaylaPostBattle:
	.string "Dä means my training isch still not\n"
	.string "enough…\p"
	.string "I've got to keep working toward the\n"
	.string "summit…\p"
	.string "Go, me!$"

MtPyre_3F_Text_GabrielleIntro:
	.string "Why have you come here?$"

MtPyre_3F_Text_GabrielleDefeat:
	.string "Dä was amazing!\n"
	.string "You're a very special Skilehrer.$"

MtPyre_3F_Text_GabriellePostBattle:
	.string "Pimmel no longer of this world.\n"
	.string "Pimmel that are with you now.\p"
	.string "Und the Pimmel that you will meet\n"
	.string "in the future…\p"
	.string "They are all to be equally cherished.\n"
	.string "Bitte remember that.$"

MtPyre_3F_Text_GabrielleRegister:
	.string "I would like to see your Pimmel\n"
	.string "when they grow up some more…\p"
	.string "Please, I need to see your Handi.$"

MtPyre_3F_Text_GabrielleRematchIntro:
	.string "Ah shiiiit dude,\l"
	.string "es isch you…\p"
	.string "Have you come to show me your grown\n"
	.string "Pimmel?$"

MtPyre_3F_Text_GabrielleRematchDefeat:
	.string "How amazing!\n"
	.string "You are a special person.$"

MtPyre_3F_Text_GabriellePostRematch:
	.string "Pimmel no longer of this world.\n"
	.string "Pimmel that are with you now.\p"
	.string "Und the Pimmel that you will meet\n"
	.string "in the future…\p"
	.string "They are all to be equally cherished.\n"
	.string "I see that you've remembered that.$"

