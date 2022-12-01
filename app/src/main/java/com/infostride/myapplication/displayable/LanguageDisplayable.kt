package com.infostride.myapplication.displayable

import android.os.Build
import com.infostride.myapplication.BasicStreamInfo
import java.util.*

val BasicStreamInfo.displayableLanguage: String?
    get() = language?.let {
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.LOLLIPOP) {
            val capitalizedLanguage = (Locale.forLanguageTag(language).getDisplayLanguage(Locale.US)
                ?: language).replaceFirstChar { if (it.isLowerCase()) it.titlecase(Locale.getDefault()) else it.toString() }

            if (capitalizedLanguage.isNotEmpty()) {
                return capitalizedLanguage
            }
        }
        return null
    }
