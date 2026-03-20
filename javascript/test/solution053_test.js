var assert = require('assert');
var solution053 = require('../src/euler/solution053');

describe('Solution053', function() {
  describe('answer', function() {
    it('will answer problem 053', function() {
      assert.equal(solution053.answer(), 4075);
    });
  });
});