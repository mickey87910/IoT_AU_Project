import React from 'react';
import { Text, View } from 'react-native';
import { createAppContainer } from 'react-navigation';
import { createBottomTabNavigator } from 'react-navigation-tabs';

class HomeScreen extends React.Component {
  render() {
    return (
      <View style={{ flex: 1, justifyContent: 'center', alignItems: 'center' }}>
        <Text>即時顯示溫濕度資料</Text>
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