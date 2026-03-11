import {createI18n} from "vue-i18n";

// The trimmed UI ships with a single built-in locale.
import en from './public/assets/locale/en.json'

export default async function() {
    const locale = 'en';
    document.querySelector('html').setAttribute('lang', locale);
    const i18n = createI18n({
        locale,
        fallbackLocale: 'en',
        messages: { en }
    })
    return i18n;
}
