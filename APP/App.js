import React from 'react';
import { Text, View } from 'react-native';
import { createAppContainer } from 'react-navigation';
import { createBottomTabNavigator } from 'react-navigation-tabs';
import IconFA from 'react-native-vector-icons/FontAwesome';
import IconMCI from 'react-native-vector-icons/MaterialCommunityIcons';
class HomeScreen extends React.Component {
  render() {
    return (
      <View style={{ flex: 1, justifyContent: 'center', alignItems: 'center' }}>
        <IconFA name="thermometer-3" size={64} color="red" />
        <Text>即時顯示溫濕度資料</Text>
        <IconMCI name="water-percent" size={80} color="blue"></IconMCI>
      </View>
    );
  }
}

class SettingsScreen extends React.Component {
  render() {
    return (
      <View style={{ flex: 1, justifyContent: 'center', alignItems: 'center' }}>
        <Text>歷史資料庫位置</Text>
      </View>
    );
  }
}

const TabNavigator = createBottomTabNavigator({
  主頁面: HomeScreen,
  歷史資料庫: SettingsScreen,
});

export default createAppContainer(TabNavigator);